#include <bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(long long l=0,r=1;l<=n;l++){
		while(a[r+1]*(r+1-l)-(sum[r+1]-sum[l])<=m&&r+1<=n)r++;
		//cout<<l<<" "<<r<<endl;
		ans=max(ans,r-l);
	}
	cout<<ans;
}
