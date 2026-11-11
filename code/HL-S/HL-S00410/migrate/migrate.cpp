// SPDX-License-Identifier: MPL-2.0
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* in=fopen("migrate.in","r");
    FILE* out=fopen("migrate.out","w");
    int n,c;
    fscanf(in,"%d %d",&c,&n);
    for(int i=0;i<n;i++){
        int n2,k;
        fscanf(" %d %d",&n2,&k);
        fprintf(out,"%d\n",(n2-1)/k);
        for(int j=0;j<n2;j++){
            fscanf(" %d",&k);
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
