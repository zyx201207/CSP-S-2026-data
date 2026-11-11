#include <bits/stdc++.h>
using namespace std;
long long a[10005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,answer=0;
	scanf("%lld/n%lld",n,m);
	for(int i=0;i<n;i++){
		scanf("%lld",a[i]);
	}
	long long num;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;i++){
			if(a[j]<a[j+1]){
				num=a[j];
				a[j]=a[j+1];
				a[j+1]=num;
			}
		}
	}
	long long c;
	for(int i=0;i<n;i++){
		c=a[i]*(i+1);
		if(i!=0){
			for(int j=0;j<=i;j++){
				c=c-a[j];
			}
		}
		if(c<=m){
			answer=i;
			break;
		}
	}
	printf("%lld",answer);
	return 0;
}
