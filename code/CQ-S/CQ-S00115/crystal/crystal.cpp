#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5002],b[5002][5002],c[5002];
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;++i){
		for(long long j=i;j<n;++j){
			b[i][j]=a[j]-a[i];
		}
	}
	for(long long i=0;i<n;++i){
		for(long long j=0;j<n;++j){
			c[j]+=b[i][j];
		}
	}
	for(long long i=n-1;i>=0;--i){
		if(m>=c[i]){
			cout<<i+1;
			return 0;
		}
	}
	return 0;

}

