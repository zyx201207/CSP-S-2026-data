#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qzh[500005];
bool check(long long k){
	for(long long i=k;i<=n;i++)
		if((k-1)*a[i]-(qzh[i-1]-qzh[i-k])<=m){return 1;}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)qzh[i]=qzh[i-1]+a[i];
	long long l=1,r=n,ans=-1;
	while(l<=r){
		long long m=(l+r)/2;
		if(check(m))l=m+1,ans=m;
		else r=m-1;
	}
	cout<<ans;
	return 0;
}

