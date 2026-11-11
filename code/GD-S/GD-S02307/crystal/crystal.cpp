#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, bu = 1e12;
int a[N], q[N], n, m, ans;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += bu;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		q[i] = q[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i - 1, ret = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (mid * a[i] - (q[i - 1] - q[i - mid - 1]) <= m)
			{
				ret = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		ans = max(ans, ret + 1);
	}
	cout << ans;
	return 0;
}
