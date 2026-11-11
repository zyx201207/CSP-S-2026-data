#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int n, a[N];
char c[N];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> c[i];
	int l = 1, r = n, ls = a[1], rs = a[n], ans = 0;
	while (l < r)
	{
		int k = min(ls, rs);
		ls -= k, rs -= k;
		ans += k * (c[l] != c[r]);
		if (!ls)
			++l, ls = a[l];
		if (!rs)
			--r, rs = a[r];
	}
	cout << ans << '\n';
	return 0;
}
