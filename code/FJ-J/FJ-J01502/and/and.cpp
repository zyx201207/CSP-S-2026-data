#include <bits/stdc++.h>
int arr[200000];
int max=0;
int n,m;
int func(const void* a,const void* b){
	return *((int *)a) < *((int *)b);
}
/*int sort(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j] < arr[j+1]){
				int tmp=arr[j];
				arr[j] = arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
	
}*/
int solve(){
	max=arr[0];
	for(int i=0;i<m;i++){
		max = arr[i] & max;
		//printf("Tmp:%d\n",max);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	qsort(arr,n,sizeof(int),func);
	solve();
	printf("%d",max);
	return 0;
}


//must be 2^n -1 ,eg. 1 11 111 1111
//e.g 1111
//    1100

