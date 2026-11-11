#include <bits/stdc++.h>
#define int long long
using namespace std;
int c;
int m, n, d, q;
int w[500010], k[510];
vector <int> a[510], t[510];
vector <pair <int, int> > cro[500010]; // 经过 i 的所有地铁
int f[510][510];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c;
	cin >> n >> m;
	cin >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].resize(k[i] + 10);
		t[i].resize(k[i] + 10);
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			cro[a[i][j]].emplace_back(make_pair(i, t[i][j]));
		}
	}
	
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int u = 1; u <= m; u++) for (auto &x: cro[u]) for (auto &y: cro[u]) { // 看起来会炸但是就是 O(d \sum k) 
		if (x.first == y.first) continue;
		f[x.first][y.first] = f[y.first][x.first] = x.second + y.second;
	}
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x == y) { // 万一呢 
			cout << "0\n";
			continue;
		}
		int ans = 1e18;
		for (auto &i: cro[x]) for (auto &j: cro[y]) ans = min(ans, f[i.first][j.first] + i.second + j.second);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
