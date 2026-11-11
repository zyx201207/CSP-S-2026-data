#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[50005], tot[505], a[505][50005], t[505][50005];
int dis[305][305];
vector <int> v[305], g[500005];
struct node {
	int v, w;
};
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> tot[i];
		for (int j = 1; j <= tot[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	if (c >= 7 && c <= 11) {
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				dis[i][j] = 2e18;
		for (int i = 1; i <= m; i++)
			dis[i][i] = 0;
		for (int i = 1; i <= n; i++) {
			dis[a[i][1]][a[i][2]] = 0;
			dis[a[i][2]][a[i][1]] = 0;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 2; j++)
				v[a[i][j]].push_back(i);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 2; j++)
				for (int p = 0; p < (int)v[a[i][j]].size(); p++) {
					int k = v[a[i][j]][p], op;
					if (a[k][1] == a[i][j]) op = 1;
					else if (a[k][2] == a[i][j]) op = 2;
					dis[i][j] = min(dis[i][j], t[i][j] + t[op][k]);
				}
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << dis[x][y] + w[x] + w[y] << "\n";
		}
	}
	return 0;
}
