#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
constexpr int N = 5e5 + 5, mod = 998244353;
i64 n, m, a[N], s[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i, t = i;
		while (l <= r)
		{
			int mid = l + r >> 1;
			i64 sum = a[i] * (i - mid + 1) - (s[i] - s[mid - 1]);
			if (sum <= m)
			{
				t = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans = max(ans, i - t + 1);
	}
	cout << ans;
	return 0;
}
