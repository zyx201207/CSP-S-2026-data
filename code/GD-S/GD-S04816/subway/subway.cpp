#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 505;
const int M = 5e5 + 10;
int c, n, m, d, q;
int w[M];
int f[N][N];
int x, y;
vector<pair<int, int> > rail[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) 
		cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, a, t; j <= k; j++) {
			cin >> a >> t;
			rail[a].push_back({i, t});
		}
	}
	memset(f, 63, sizeof(f));
	for (int i = 1; i <= m; i++) 
		for (auto j : rail[i]) for (auto k : rail[i]) {
			int u = j.first, v = k.first;
			int c1 = j.second, c2 = k.second;
			f[u][v] = min(f[u][v], c1 + c2);
			f[v][u] = min(f[v][u], c1 + c2);
		}
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		cin >> x >> y;
		int add = w[x] + w[y], ans = LLONG_MAX;
		for (auto i : rail[x]) for (auto j : rail[y]) {
			int u = i.first, v = j.first;
			int c1 = i.second, c2 = j.second;
			ans = min(ans, f[u][v] + c1 + c2 + add);
		}
		cout << ans << endl;
	}
	return 0;
}
