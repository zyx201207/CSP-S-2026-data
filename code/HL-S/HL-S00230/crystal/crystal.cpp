#include<bits/stdc++.h>
using namespace std;
long long a[500009];
long long b[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ret=1,cnt=0,s=1;//cnt是累加的能量 ret是答案 
	scanf("%lld%lld", &n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		b[i]=a[n]-a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		if(s<i) s=i;
		for(int j=s;j<=n;j++){
			if(b[i]-b[j]>m){
				s=j-1;
				break;
			}
			if(j==n){
				s=n;
			}
		}
		ret=max(ret,s-i+1);
	}
	printf("%lld", ret);
	return 0;
}
//10 3
//1 10 11 12 20 23 23 23 24 100
