#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 5e5 + 10;
const int M = 2.5e5 + 10;

int c, n, m, d, q;
int w[M], t[505][M];
i64 f[505][505], ans, l, r;
vector<int> g[M];

void solve () {
	for (int i = 1; i <= n * (n + 1) >> 1; i++) {
		for (auto u : g[i]) {
			for (auto v : g[i]) {
				if (u == v) continue;
				f[u][v] = min(f[u][v], 1LL * t[u][i] + t[v][i]);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) f[i][j] = 0;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway3.in", "r", stdin);
	freopen("subway3.out", "w", stdout);
	
	memset(f, 0x3f, sizeof(f));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a;
			cin >> a >> t[i][a];
			g[a].push_back(i);
		}
	}
	solve();
	while (q--) {
		int s, e;
		ans = 0x3f3f3f3f;
		cin >> s >> e;
		for (auto i : g[s]) {
			for (auto j : g[e]) {
				if (i == j) {
					ans = 0;
					l = t[i][s], r = t[i][e];
				}
				if (min(f[i][j], f[j][i]) < ans) {
					l = t[i][s], r = t[j][e];
					ans = min(f[i][j], f[j][i]);
				}
			}
		}
		cout << "l:" << l << " r:" << r << " ans:" << ans << '\n';
		cout << (w[s] + w[e] + l + r + ans) << '\n';
	}
	
	return 0;
}
