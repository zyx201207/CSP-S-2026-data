#include<bits/stdc++.h>
using namespace std;
const long long N=1e8+10;
long long a[N];
int main(){//noÌ«ÄÑÁË£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ct=0;
	if(m<=2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				long long x=a[i];
				if(ct<(x&a[j])){
					ct=x&a[j];
				}
			}
		}
	}else{
		sort(a+1,a+n+1);
		long long x=a[n];
		long long ans=n-1;
		m-=1;
		while(m--){
			x&=a[ans];
			//cout<<x<<" ";
			ans--;
		}
		ct=x;
	}
	cout<<ct;
	return 0;
}
