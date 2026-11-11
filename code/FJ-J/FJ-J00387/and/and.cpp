#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;

int n, m, a[N], ans;

signed main()
{
//	string cid ; cin >> cid;
//	string s1 = "and" + cid + ".in", s2 = "and" + cid + ".out";
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int j = 29; ~j; --j)
	{
		int k = 0;
		for (int i = 1; i <= n; ++i) if (a[i] & (1 << j)) ++k;
		if (k < m) continue;
		k = 0;
		for (int i = 1; i <= n; ++i) if (a[i] & (1 << j)) a[++k] = a[i];
		ans |= 1 << j;
		n = k;
	}
	cout << ans;
	return 0;
}

