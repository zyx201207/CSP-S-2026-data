#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;

int n, m, s, ans = 1, a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 2, j = 1; i <= n; ++i) {
		s += (a[i] - a[i-1]) * (i-j);
		while (s > m)
			s -= a[i] - a[j], ++j;
		ans = max(ans, i-j+1);
	}
	return cout << ans, 0;
}
