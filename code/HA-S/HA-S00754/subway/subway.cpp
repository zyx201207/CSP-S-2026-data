#include <bits/stdc++.h>
using namespace std;
const int N = 501, M = 20001;
int c, n, m, d, q, k[N], w[M];
int g[M][M];
vector<int> a[N], t[N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	memset(g, 0x3f3f3f3f, sizeof(g));
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for (int j = 1; j <= k[i]; j++) {
			int aa, tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int x = 1; x <= k[i]; x++)
			for (int y = 1; y <= k[i]; y++)
				g[a[i][x]][a[i][y]] = g[a[i][y]][a[i][x]] = min(g[a[i][x]][a[i][y]], t[i][x] + t[i][y]);
	for (int i = 1; i <= m; i++) g[i][i] = 0;
	while (d--) {
		for (int i = 1; i <= m; i++) {
			g[i][i] = 0;
			for (int j = i + 1; j <= m; j++)
				for (int k = 1; k <= m; k++)
					g[j][i] = g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + g[x][y] << "\n";
	}
	return 0;
}
