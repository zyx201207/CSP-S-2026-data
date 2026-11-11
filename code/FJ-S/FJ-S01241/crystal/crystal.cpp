#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005];
bool check(int mid)
{
	for(int i = mid;i <= n;i++)
	{
		int j = i-mid+1;
		if(mid*a[i]-(sum[i]-sum[j-1]) <= m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+a[i];
	int l = 1,r = n,ans;
	while(l <= r)
	{
		int mid = (l+r) >> 1;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout << ans;
	return 0;
}
