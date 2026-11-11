#include<bits/stdc++.h>
#define tin long long
using namespace std;
tin n,m,a[500005],sum[500005];
bool check(tin x){
	tin now=1e18;
	for(tin i=x;i<=n;i++)
		now=min(now,a[i]*(x-1)-(sum[i-1]-sum[i-x]));
	return (now<=m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(tin i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(tin i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	tin l=1,r=n,ans=0;
	while(l<=r){
		tin mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}cout<<ans;
	return 0;
}
