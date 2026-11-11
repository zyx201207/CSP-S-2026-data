#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int w[m];
	for (int i = 0; i < m; i++) cin >> w[i];
	bool route[m][n];
	int t[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			route[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < n; j++) {
			int a, T;
			cin >> a >> T;
			route[i][a] = true;
			t[i][a] = T;
		}
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		if (n <= 3) {
			int firstTo2_min = 1e9;
			int firstTo3_min = 1e9;
			int secondTo3_min = 1e9;
			int ans = w[x - 1] + w[y - 1];
			for (int j = 0; j < m; j++) {
				if (route[0][j] && route[1][j]) {
					int e = t[0][j] + t[1][j];
					if (e > firstTo2_min) firstTo2_min = e;
				}
				if (route[2][j] && route[1][j]) {
					int e = t[2][j] + t[1][j];
					if (e > secondTo3_min) secondTo3_min = e;
				}
				if (route[0][j] && route[2][j]) {
					int e = t[0][j] + t[2][j];
					if (e > firstTo3_min) firstTo3_min = e;
				}
			}
			int min = 0;
			int p, q;
			if ((!(route[0][x] && route[0][y])) && 
			(!(route[1][x] && route[1][y])) && 
			(!(route[2][x] && route[2][y]))) {
				if ((route[0][x] && route[1][y]) || route[1][x] && route[0][y]) {
					min = firstTo2_min;
					p = 0;
					q = 1;
				}
				if ((route[0][x] && route[2][y]) || route[2][x] && route[0][y]) {
					if (firstTo3_min < min) min = firstTo3_min;
					p = 0;
					q = 2;
				}
				if ((route[2][x] && route[1][y]) || route[1][x] && route[2][y]) {
					if (secondTo3_min < min) min = secondTo3_min;
					p = 1;
					q = 2;
				}
			}
			ans += min;
			ans += t[p][x - 1] + t[q][y - 1];
			cout << ans << endl;
		}
	}
	return 0;
}
