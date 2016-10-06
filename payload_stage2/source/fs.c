/*
*   fs.c
*/

#include "fs.h"
#include "fatfs/ff.h"

static FATFS fs;

bool mountSd(void)
{
    return f_mount(&fs, "0:", 1) == FR_OK;
}

u32 fileRead(void *dest, const char *path, u32 maxSize)
{
    FIL file;
    u32 ret = 0;

    if(f_open(&file, path, FA_READ) == FR_OK)
    {
        u32 size = f_size(&file);
        if(size <= maxSize)
            f_read(&file, dest, size, (unsigned int *)&ret);
        f_close(&file);
    }

    return ret;
}