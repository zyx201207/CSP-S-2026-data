#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, M = 5005, inf = 1e18;
int c, T, n, d, a[N];
int f[M][M], g[M][M];
void solveBrute() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = inf;
			g[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = 0;
		g[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = i; k <= j - 1; k++) {
				if (a[j] - a[k] <= d) {
					if (f[i][k] + 1 < f[i][j]) {
						f[i][j] = f[i][k] + 1;
						g[i][j] = g[i][k];
					} else if (f[i][k] + 1 == f[i][j]) {
						g[i][j] += g[i][k];
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
//			cout << "from " << i << " to " << j << ", sPathCnt = " << g[i][j] << '\n';
			if (g[i][j] == 2) ans++;
		}
	}
	cout << ans << '\n';
}
void solveA() {
	int diff = a[2] - a[1];
	int per = d / diff;
	int best = per + (per - 1) + 1;
	if (d < 2 * diff or best > n) {
		cout << 0 << '\n';
		return;
	}
	cout << n - best + 1 << '\n';
}
signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (1 <= c and c <= 10) {
			solveBrute();
		} else if (11 <= c and c <= 12) {
			solveA();
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}

