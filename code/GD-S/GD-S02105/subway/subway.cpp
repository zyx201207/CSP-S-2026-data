#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, f[1005][1005], w[500005], num[505][1005], t[505][1005], k[505];
void Floyd () {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (f[i][j] > f[i][k] + f[k][j])
					f[i][j] = f[i][k] + f[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] += w[i] + w[j];
		}
	}
}
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> num[i][j] >> t[i][j];
			for (int k = 1; k < j; k++) {
				int x = num[i][j], y = num[i][k];
				f[x][y] = f[y][x] = t[i][j] + t[i][k];
			}
		}
	}
	Floyd ();
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << f[x][y] << endl;
	}
	return 0;
}

