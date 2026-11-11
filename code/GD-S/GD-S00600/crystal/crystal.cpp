#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
ll a[500005];
ll b[500005];
ll c[500005];
ll y=0;
void solve()
{
	ll n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		
	}
	
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		b[i] = b[i-1]+a[i];
	}
	ll ans =0;
	ll l = 0,r = n;
	while(l <= r)
	{
		ll mid=(l+r)/2;
		ll ans1 = 1e18;
		for(int i =mid;i <= n;i++)
		{
			ll cnt = a[i]*(mid)-b[i]+b[i-mid];
			ans1 = min(ans1,cnt);
		} 
		if(ans1 <= m)
		{
			ans = mid;
			l = mid+1;
		}
		else
		{
			r = mid-1;
		} 
		
	}
	cout << ans << endl;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll t =1;
//	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
} 
