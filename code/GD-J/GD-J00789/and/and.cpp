#include <bits/stdc++.h>
using namespace std;
int n, m, t, u, v = 1073741823, w, x = 1e9, y = 1073741823, a[200005];
void dfs(int k, int ans, int cnt) {
	if (cnt > m) {
		return;
	}
	if (k > n) {
		if (cnt == m) {
			t = max(t, ans);
		}
		return;
	}
	dfs(k + 1, ans & a[k], cnt + 1);
	dfs(k + 1, ans, cnt);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		u = max(u, a[i]);
		v &= a[i];
		x = min(x, a[i]);
	}
	if (n <= 20) {
		dfs(1, 1073741823, 0);
		cout << t;
	} else if (n <= 2000) {
		if (m == 1) {
			cout << u;
		} else if (m == n) {
			cout << v;
		} else if (m == 2) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j < i; j++) {
					w = max(w, a[i] & a[j]);
				}
			}
			cout << w;
		}
	} else {
		if (m == 1) {
			cout << u;
		} else if (m == n) {
			cout << v;
		} else if (m == 2) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j < i; j++) {
					w = max(w, a[i] & a[j]);
				}
			}
			cout << w;
		} else {
			sort(a + 1, a + n + 1, greater<int>());
			cout << a[m];
		}
	}
	return 0;
}
