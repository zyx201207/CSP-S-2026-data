#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10;
int n, m;
int a[N], s[N];

bool check(int x)
{
	for (int i = x; i <= n; ++i)
	{
		if (x * a[i] - (s[i] - s[i-x]) <= m)
			return 1;
	}
	return 0;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i-1] + a[i];
	int l = 1, r = n, ans = 0;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
