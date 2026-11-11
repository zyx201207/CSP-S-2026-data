// 1

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kM = 2e6 + 7;

int c, t, n, d, a[kM], cnt = 0, aa;
vector<int> g[kM];

void dfs(int st, int l, int ed, int maxl) {
	if (l > maxl) {
		return;
	}
	if (st == ed && l == maxl) cnt++;
	for (auto v : g[st]) {
		dfs(v, l + 1, ed, maxl);
	}
}

void solve() {
	aa = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (abs(a[i] - a[j]) <= d) {
				g[i].push_back(j);
				g[j].push_back(i); 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		queue<int> q;
		vector<int> vis(n + 2, 0), ans(n + 2, 2e18 + 7);
		q.push(i);
		ans[i] = 0;
		vis[i] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto v : g[u]) {
				if (vis[v] == 0) {
					vis[v] = 1;
					ans[v] = ans[u] + 1;
					q.push(v);
				}
			}
		}
//		vector<int> vv(n + 2, 0);
		for (int k = 1; k <= n; k++) {
			cnt = 0;
			dfs(i, 0, k, ans[k]);
			if (cnt == 2) {
				aa++;
			}
//			cout << cnt << "\n";
		}
	}
	cout << aa / 2 << "\n";
}

void solve1() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int k = lower_bound(a + 1, a + n + 1, a[1] + d) - a - 1;
	cout << (n - k) << "\n";
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> t;
	if (c == 11 || c == 12) {
//		cout << "Jin\n";
		while (t--) solve1();
		return 0;
	}
	while (t--) solve();
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
4 2
1 2 3 4

*/
