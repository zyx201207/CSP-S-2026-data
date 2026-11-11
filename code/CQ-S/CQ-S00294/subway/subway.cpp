#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int w[500005], dis[505][505];
vector<pair<int, int>> vt[500005];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 1; j <= num; j++) {
			int x, t;
			cin >> x >> t;
			vt[x].push_back({i, t});
		}
	}
//	for (int i = 1; i <= m; i++) {
//		cout << i << '\n';
//		for (auto v : vt[i]) {
//			cout << v.first << ' ' << v.second << '\n';
//		}
//	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (auto it1 : vt[i]) {
			for (auto it2 : vt[i]) {
				int u = it1.first;
				int tu = it1.second;
				int v = it2.first;
				int tv = it2.second;
				if (u == v) continue;
				dis[u][v] = min(dis[u][v], tu + tv);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dis[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] != 0x3f3f3f3f3f3f3f3f && dis[k][j] != 0x3f3f3f3f3f3f3f3f) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 	
				}
				
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		int ans = w[u] + w[v], cnt = 4e18;
//		cout << vt[u].size() << '\n' << vt[v].size() << '\n';
		for (auto it1 : vt[u]) {
			for (auto it2 : vt[v]) {
				int nu = it1.first;
				int tu = it1.second;
				int nv = it2.first;
				int tv = it2.second;
//				if (nu == nv) continue;
//				cout << u << ' ' << v << '\n'; 
				cnt = min(cnt, dis[nu][nv] + tu + tv);
			}
		}
		ans = ans + cnt;
		cout << ans << '\n';
	}
	return 0;
}

