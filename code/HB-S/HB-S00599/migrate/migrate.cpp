#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 5;
int c, T;
int n, d, a[N], ans;

bool vis[N];
int sum, mn = 3e18;

void dfs (int x, int ed, int len) {
	if (x == ed) {
		if (len == mn) {
			sum ++;
			return;
		}
		if (len < mn) {
			mn = len;
			sum = 1;
		}
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (vis[i] || abs (a[i] - a[x]) > d) continue;
		vis[i] = 1;
		dfs (i, ed, len + 1);
		vis[i] = 0;
	}
}

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);

	cin >> c >> T;
	while (T --) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		if (n <= 2) {cout << "0\n"; continue;}
		// ====================
		if (c == 1 || c == 2) {
			for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) {
				memset (vis, 0, sizeof vis);
				vis[i] = 1;
				sum = 0;
				mn = 3e18;
				dfs (i, j, 0);
				if (sum == 2) {ans ++;}
			}
			cout << ans << "\n";
			continue;
		}
		if (c == 11 || c == 12 || c == 0) {
			int zl = a[2] - a[1];
			int mx = d / zl;
			int L = mx + 1;
			int R = 2 * mx - 1;
			if (L > R) {cout << "0\n"; continue;}
			for (int i = L + 1; i <= n; i ++) {
				if (i - R > 0)
					ans ++;
			}
			cout << ans << "\n";
		}
	}
}
