// SPDX-License-Identifier: MPL-2.0
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define array(type) typedef struct type##_array{\
    size_t curr_size,max_size;\
    type* datas;\
}type##_array;\
int type##_array_init(type##_array* self){\
    self->curr_size=0;\
    self->max_size=4;\
    self->datas=(type*)malloc(4*sizeof(type));\
    return !self->datas;\
}\
int type##_array_push(type##_array* self,type value){\
    if(self->curr_size==self->max_size){\
        void* tmp=realloc(self->datas,self->max_size>>=1);\
        if(!tmp){\
            free(self->datas);\
            return 1;\
        }\
        self->datas=(type*)tmp;\
    }\
    self->datas[self->curr_size++]=value;\
    return 0;\
}
array(int);
array(char);
char getchar_from(int_array* a,char_array* b,size_t index){
    size_t i2=0,i3=0;
    while(index>=i2){
        i2+=a->datas[i3];
        i3++;
    }
    i3--;
    return b->datas[i3];
}
size_t test_char(int_array* a,char_array* b,size_t total){
    size_t res=0;
    for(size_t i=0;i<(total>>2);i++){
        res+=(getchar_from(a,b,i)!=getchar_from(a,b,total-i-1));
    }
    return res;
}
int main(){
    fprintf(stderr,"在加载时出错：缺少所需的库 \nglibc.so\nglibc_ext.so\nglibc_old.so\n");
	FILE* in=fopen("string.in","r");
	FILE* out=fopen("string.out","w");
	size_t n;
	fscanf(in,"%ld",&n);
	int_array arr;
	char_array c;
	size_t total=0;
	if(int_array_init(&arr)||char_array_init(&c))return 1;
	for(int i=0;i<n;i++){
        int i2;
        char c2;
        fscanf(in,"\n%d %c",&i2,&c2);
        if(int_array_push(&arr,i2)||char_array_push(&c,c2))return 1;
        total+=i2;
	}
	fprintf(out,"%ld\n",test_char(&arr,&c,total));
    fclose(in);
    fclose(out);
	return 0;
}
