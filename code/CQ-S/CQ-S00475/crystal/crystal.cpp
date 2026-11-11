#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll a[500001];
ll sum[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for (ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll ans=1;
	for (ll i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		ll l=1,r=i;
		while (l<r)
		{
			ll mid=(l+r)/2;
			if (m>=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
