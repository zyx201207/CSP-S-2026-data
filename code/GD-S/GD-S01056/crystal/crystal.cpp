#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[500005],ans,c[500005],dp[500005];
bool ck(int x){
	int sum=1e18;
	for(int i=1;i<=n;i++)	dp[i]=0;
	for(int i=1;i<=x;i++)	dp[x]+=c[i]*(i-1);
	for(int i=x+1;i<=n;i++)
		dp[i]=dp[i-1]-c[i-x+1]-(a[i-1]-a[i-x+1])+c[i]*(x-1);
	for(int i=x;i<=n;i++)	sum=min(dp[i],sum);
//	cout<<endl;
	if(sum<=m)	return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)	c[i]=a[i]-a[i-1];
//	for(int i=1;i<=n;i++)	cout<<c[i]<<" ";
	int l=1,r=n;
	while(l<r){
//		cout<<l<<" "<<r<<endl;
		if(r-l<=1){
			if(ck(r))	ans=r;
			ans=l;
			break;
		}
		int mid=(l+r)>>1;
		if(ck(mid))	l=mid,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
