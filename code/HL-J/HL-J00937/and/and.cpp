// SPDX-License-Identifier: MPL-2.0
#include<stdio.h>
#include<stdint.h>
int main(){
	FILE* in=fopen("and.in","r");
	FILE* out=fopen("and.out","w");
	int n,m;
	scanf("%d %d",&n,&m);
	int* target=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)scanf(" %d",target+i);
    if(m>1){
        int max=-1;
        int* choiced=(int*)malloc(sizeof(int)*m);
        for(int i=0;i<m;i++)choiced[i]=i;
        for(int i=0;;i++){
            int curr=0x3fffffff;
            for(int j=0;j<m;j++)curr&=target[choiced[j]];
            max=max>curr?max:curr;
            int j;
            for(j=n-1;!j||choiced[m+j-n]==j;j--);
            if(!j)break;
            for(int k=1;k+j<m;k++)choiced[m+j-n+k]=choiced[m+j-n]+k+1;
            choiced[m+j-n]+=1;
        }
        free(choiced);
        fprintf("%d\n",max);
    }
    else{
        int max=-1;
        for(int i=0;i<n;i++){
            if(target[i]>max)max=target[i];
        }
        fprintf("%d\n",max);
    }
    free(target);
    fclose(in);
    fclose(out);
	return 0;
}
