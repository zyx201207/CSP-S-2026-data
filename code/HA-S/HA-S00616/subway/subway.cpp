#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1010, M = 5000010;
int c, n, m, d, q, w[N], dis[N][N], tot, k, xx[N], yy[N];
void floyed() {
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	return;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) dis[i][j] = 1e18;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) cin >> xx[j] >> yy[j];
		for (int j = 1; j <= k; j++) {
			for (int l = 1; l <= k; l++) {
				if (j == l) continue;
				dis[xx[j]][xx[l]] = yy[j] + yy[l];
			}
		}
	}
	floyed();
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}
