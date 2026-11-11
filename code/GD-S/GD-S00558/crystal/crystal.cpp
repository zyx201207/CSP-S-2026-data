#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD=1e9+7;
const ll MAXN=5e5+5;
const ll inf=LONG_LONG_MAX;
ll n,m,a[MAXN],sum[MAXN];
bool ss(ll x)
{
	for(int i=x;i<=n;i++)
	{
		if(x*a[i]-(sum[i]-sum[i-x])<=m)return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	ll l=0,r=n+1;
	while(l+1<r)
	{
		ll mid=l+r>>1;
		if(ss(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
