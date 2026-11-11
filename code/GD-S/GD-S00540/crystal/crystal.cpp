#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,m;
ll a[500005];
ll sum[500005];
ll erfen(ll x)//合成均为a[x]的水晶 
{
	ll l=1,r=x,ans=1;//将[mid,x]之间的水晶操作 
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if((x-mid+1)*a[x]-(sum[x]-sum[mid-1])<=m)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return x-ans+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,erfen(i));
	}
	cout<<ans;
	return 0;
}
