#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],sum[500005];
bool check(ll x)
{
	ll minn=1e18;
	for(int i=x;i<=n;i++)
	{
		ll ans=a[i]*x-(sum[i]-sum[i-x]);
		minn=min(minn,ans);
	}
	//cout<<minn<<" ";
	if(minn<=m)return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
