#include <bits/stdc++.h>

#define int long long

using namespace std;

const int M = 5e3 + 5;

const int N = 505;

int c, n, m, d, q;

int w[M];

int k[N];

int a[N][N], t[N][N];

int dis[M][M];

signed main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	ios :: sync_with_stdio (0), cin.tie (0);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			dis[i][j] = 1e17;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= k[i]; j++) {
			for (int p = 1; p <= j; p++) {
				if (dis[a[i][p]][a[i][j]] == 1e17)
					dis[a[i][p]][a[i][j]] = dis[a[i][j]][a[i][p]] =  t[i][p] + t[i][j];
				else 
					dis[a[i][p]][a[i][j]] = dis[a[i][j]][a[i][p]] = min (dis[a[i][p]][a[i][j]], t[i][p] + t[i][j]);
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int p = 1; p <= m; p++) {
				dis[j][p] = min (dis[j][p], dis[j][i] + dis[i][p]);
			}
		}
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}
