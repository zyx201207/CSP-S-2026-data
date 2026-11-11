#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n, m, a[N], f[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if ((i - mid + 1) * a[i] - (f[i] - f[mid - 1]) <= m)
			{
				r = mid - 1;
				ans = max(ans, i - mid + 1);
			} else l = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
