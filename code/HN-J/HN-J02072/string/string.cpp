#include<bits/stdc++.h>
using namespace std;
long long n,arr[200010];
char c[200010];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n); 
	for(long long i=0;i<n;i++){
		scanf("%d",&arr[i]);
		char cc;
		scanf("%c",&cc);
		scanf("%c",&c[i]);
	}
//	for(int i=0;i<n;i++){
//		printf("%d %c\n",arr[i],c[i]);
//	} 

	long long i=0,j=n-1;
	while(i<j){
//		printf("%d %d %d %d %d\n",i,j,ans,arr[i],arr[j]);
		if(c[i]==c[j]){
			if(arr[i]==arr[j]){
				arr[i]=arr[j]=0;
				i++,j--; 
//				printf("1 1\n");
			}else if(arr[i]>arr[j]){
				arr[i]-=arr[j];
				arr[j]=0;
				j--;
//				printf("1 2\n");
			}else{
				arr[j]-=arr[i];
				arr[i]=0;
				i++;
//				printf("1 3\n");
			}
		}else{
			if(arr[i]==arr[j]){
				ans=ans+arr[i];
				arr[i]=arr[j]=0;
				i++,j--;
//				printf("2 1\n");
			}else if(arr[i]>arr[j]){
				arr[i]-=arr[j];
				ans=ans+arr[j];
				arr[j]=0;
				j--;
//				printf("2 2\n");
			}else{
				arr[j]-=arr[i];
				ans=ans+arr[i];
				arr[i]=0;
				i++;
//				printf("2 3\n");
			}
		}
//		printf("%d %d %d %d %d\n\n",i,j,ans,arr[i],arr[j]);
	}
	
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
15
23 s
65 d
34 h
16 u
46 f
75 r
43 j
64 f
45 w
23 r
36 b
43 v
72 x
36 d
85 m
*/
