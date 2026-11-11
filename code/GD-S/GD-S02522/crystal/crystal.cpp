#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], sum[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans = -1e18;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i - 1, res = -1e18;
		while (l <= r)
		{
			int mid = l+r>>1;
			if (a[i] * mid - sum[i-1] + sum[i-1-mid] <= m)
			{
				res = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans = max(ans, res);
	}
	cout << ans+1;
	return 0;
}
