#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;
using db = double;
using ldb = long db;

const int N = 5e5 + 5;
int n, ans;
ll m, a[N], s[N];

ll calc(int l, int r) {
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal3.in", "r", stdin);
//	freopen("crystal3.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
//	cerr << m << ' ' << calc(1, n) << '\n';
	for (int i = 1, j = 1; i <= n; ++i) {
		while (calc(j, i) > m) ++j;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}

