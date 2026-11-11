#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[100005],s[1000050];
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int k=i;k<j;k++){
				if(b[k]==b[j]){
					for(int l=k;l<j;l++)b[l]=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			s[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",s[i]);
	}
	return 0;
} 
