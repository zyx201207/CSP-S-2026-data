#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], d[N], s[N], ans, l = 1, r = 1;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
		if (i == 1) d[i] = 0;
		s[i] = s[i - 1] + d[i];
	}
	int k = 0;
	while (l <= n) {
		while (r <= n && k + d[r + 1] <= m) {
			r++;
			k += d[r] * (r - l + 1);
		}
		if (r > n) break;
		ans = max(ans, r - l + 1);
		k -= s[r] - s[l - 1];
		l++;
	}
	cout << ans;
	return 0;
}

