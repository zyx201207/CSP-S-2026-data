#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, d, x[2000005];
int dis[2000005], ans[2000005];

void dfs(int u, int cnt) {
	if (u > n) return;
	if (dis[u] == -1) {
		dis[u] = cnt;
	}
	if (dis[u] == cnt) {
		ans[u]++;
	} else if (dis[u] > cnt) {
		ans[u] = 1;
		dis[u] = cnt;
	}
	for (int i = u + 1; i <= n; i++) {
		if (x[i] - x[u] <= d) dfs(i, cnt + 1);
	}
}

void solve() {
	memset(dis, -1, sizeof(dis));
	memset(ans, 0, sizeof(ans));
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	int anss = 0;
	for (int u = 1; u <= n; u++) {
		dfs(u, 0);
		for (int v = u; v <= n; v++) {
			anss += (ans[u] == 2);
		}
	}
	cout << anss << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
