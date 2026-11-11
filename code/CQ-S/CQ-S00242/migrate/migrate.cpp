#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, x[5005], oo, p[5005][5005], vis[5005];
vector<pair<int, int>> nxt[5005];
void fun(int u, int ww) {
	for (auto o : nxt[u]) {
		int v = o.first, w = o.second;
//		cout << u << " " << v << "\n";
		if (ww + w <= d && !vis[v] && v > u) {
			vis[v] = 1;
			if (u != oo && v != oo && p[oo][v] == 0) {
//				cout << oo << " " << u << " " << v << "\n";
				nxt[oo].push_back({v, ww + w});
				nxt[v].push_back({oo, ww + w});
				p[oo][v]++;
				p[v][oo]++;
			}
			fun(v, ww + w);
		}
	}
	return ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			if (i != 1 && x[i] - x[i - 1] <= d) {
				nxt[i - 1].push_back({i, x[i] - x[i - 1]});
				nxt[i].push_back({i - 1, x[i] - x[i - 1]});
				p[i][i - 1]++;
				p[i - 1][i]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			oo = i;
			vis[i] = 1;
			fun(i, 0);
		}
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			oo = i;
			vis[i] = 1;
			fun(i, 0);
		}
//		for (int i = 1; i <= n; i++) {
//			for (auto o : nxt[i]) {
//				cout << i << " " << o.first << "\n";
//			}
//		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
//				cout << p[i][j] << " ";
				if (p[i][j] == 2) {
					ans++;
				}
			}
//			cout << "\n";
		}
		cout << ans << "\n";
		for (int i = 1; i <= n; i++) {
			nxt[i].clear();
		} 
	}
	return 0;
}
//请评测机帮我删一下调试哦！（虽然没对） 
