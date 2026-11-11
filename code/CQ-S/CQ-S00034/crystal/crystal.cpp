#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[500005], sum[500005];

inline int chk(int l, int r) {
	return a[r] * (r - l + 1) - (sum[r] - sum[l - 1]) <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int l = 1, r = 1; r <= n; ++r) {
		while (l < r && !chk(l, r)) ++l;
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
	return 0;
}

