/** \file
 * \brief Data Type Utilities
 *
 * See Copyright Notice in im_lib.h
 */


#include "im.h"
#include "im_util.h"

#include <assert.h>

typedef struct _iTypeInfo
{
  int size;
  unsigned long max;
  long min;
  const char* name;
} iTypeInfo;

static iTypeInfo iTypeInfoTable[] =  
{//size  max          min             name
  {1,    255,         0,              "byte"}, 
  {2,    32767,       -32767-1,       "short"},
  {2,    65535,       0,              "ushort"},
  {4,    2147483647,  -2147483647-1,  "int"},
  {4,    0,           0,              "float"}, 
  {8,    0,           0,              "double"}, 
  {8,    0,           0,              "cfloat"},
  {16,   0,           0,              "cdouble"}
};

const char* imDataTypeName(int data_type)
{
  assert(data_type >= IM_BYTE && data_type <= IM_CDOUBLE);
  return iTypeInfoTable[data_type].name;
}

int imDataTypeSize(int data_type)
{
  assert(data_type >= IM_BYTE && data_type <= IM_CDOUBLE);
  assert(sizeof(int) == 4);
  return iTypeInfoTable[data_type].size;
}

unsigned long imDataTypeIntMax(int data_type)
{
  assert(data_type >= IM_BYTE && data_type <= IM_CDOUBLE);
  return iTypeInfoTable[data_type].max;
}

long imDataTypeIntMin(int data_type)
{
  assert(data_type >= IM_BYTE && data_type <= IM_CDOUBLE);
  return iTypeInfoTable[data_type].min;
}
