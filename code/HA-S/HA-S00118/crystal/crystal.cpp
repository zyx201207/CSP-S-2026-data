#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],sum[500005],isum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;ll m;cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		isum[i]=a[i]*(i-1)-sum[i-1];
	}
	ll cnt = -1;
	for(ll l = 1,r = l;l <= n&&r <= n;)
	{
		ll x = isum[r]-isum[l]-(l-1)*(a[r]-a[l]);
		if(x<=m)
		{
			cnt=max(cnt,r-l+1);
			r++;
		}
		else l++;
	}
	cout << cnt;
	return 0;
}
