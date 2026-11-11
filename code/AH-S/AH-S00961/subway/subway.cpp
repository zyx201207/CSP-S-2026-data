#include <bits/stdc++.h>

using namespace std;

#define ll long long

int c, n, m, d, q;
int w[500005];
vector<int> a[505], t[505];
vector<pair<int, int> > vec[500005];
ll g[505][505], dis[500005], ans[100005];
int X[100005], Y[100005], vis[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		a[i].resize(k), t[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> a[i][j] >> t[i][j]; 
			vec[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto x : vec[i]) {
			for (auto y : vec[i]) if (x != y) {
				g[x.first][y.first] = min(g[x.first][y.first], 1ll * x.second + y.second);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		} 
	}
	
//	printf("%d\n", g[1][3]);
	
	for (int i = 1; i <= q; i++) {
		cin >> X[i] >> Y[i]; 
	}
	
	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= n; i++) { // warning
		for (int j = 0; j < a[i].size(); j++) vis[a[i][j]] = t[i][j];
		memset(dis, 0x3f, sizeof(dis));
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < a[j].size(); k++) {
				dis[a[j][k]] = min(dis[a[j][k]], t[j][k] + g[i][j]);
			}
		}
//		printf("%lld %d\n", dis[6], vis[1]);
		for (int j = 1; j <= q; j++) {
			int x = X[j], y = Y[j];
			if (vis[x]) ans[j] = min(ans[j], vis[x] + dis[y]);
		}
		for (auto x : a[i]) vis[x] = 0;  
	}
	for (int i = 1; i <= q;  i++) {
		cout << ans[i] + w[X[i]] + w[Y[i]] << "\n"; 
	}
	return 0;
}
