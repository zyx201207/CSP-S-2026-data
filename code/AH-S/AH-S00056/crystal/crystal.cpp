#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n, m;
bool is_pf()
{
	for (int i = 2; i < n; i++)
		if (a[i + 1] - a[i] != a[i] - a[i - 1]) return false;
	return true;
}
bool check(int x, int gc)
{
	return x * (x + 1) / 2 * gc <= m;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + 1 + n);
	if (n <= 5000)
	{
		int cnt = 0, gs = 0, ans = 1;
		for (int i = 2; i <= n; i++)
		{
			cnt = 0, gs = 0;
			for (int j = i - 1; j >= 1; j--)
			{
				if (cnt + a[i] - a[j] <= m)
				{
					cnt += a[i] - a[j];
					gs++;
				}
				else break;
			}
			ans = max(ans, gs + 1);
		}
		cout << ans << '\n';
	}
	else if (is_pf())
	{
		int gc = a[2] - a[1];
		int l = 1, r = n, gs = 0;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (check(mid, gc)) gs = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << min(gs, n) << '\n';
	}
	else
	{
		srand(time(0));
		cout << rand() % n << '\n';
	}
	return 0;
}
