#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], ans;
inline void dfs(int x, int y, int z) {
	if (y == m) {
		ans = max(ans, z);
		return;
	}
	if (n - x < m - y) return;
	dfs(x + 1, y + 1, (z & a[x + 1]));
	dfs(x + 1, y, z);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ans = max(ans, a[i]);
		}
		cout << ans << '\n';
	} else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 1; j < i; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << '\n';
	} else if (m == n) {
		cin >> a[1];
		ans = a[1];
		for (int i = 2; i <= n; i++) {
			cin >> a[i];
			ans = (ans & a[i]);
		}
		cout << ans << '\n';
	} else {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n - m + 1; i++) {
			dfs(i, 1, a[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
