// SPDX-License-Identifier: MPL-2.0
#include<stdio.h>
#include<stdint.h>
#include<string.h>
int main(){
	FILE* in=fopen("card.in","r");
	FILE* out=fopen("card.out","w");
	int n,m;
	scanf("%d %d",&n,&m);
	int* cards=(int*)malloc(sizeof(int)*n),*simulator=(int*)malloc(sizeof(int)*n),*has=(int*)malloc(m*sizeof(int)),*has_last=(int*)malloc(m*sizeof(int));
	for(int i=0;i<n;i++)scanf(" %d",cards+i);
	for(int i=0;i<n;i++){
        int curr=0;
        memset(has,0,m*sizeof(int));
        for(int j=i;j<n;j++){
            if(!has[cards[j]]){
                has[cards[j]]=curr;
                simulator[curr++]=cards[j];
            }
            else{
                curr=has[cards[j]];
            }
        }
        if(curr==n-i)break;
        for(int j=0;j<m;j++){
            has_last[j]+=!!has[j];
        }
	}
	for(int i=0;i<m;i++){
        printf(i==m-1?"%d\n":"%d ");
	}
    fclose(in);
    fclose(out);
	return 0;
}



