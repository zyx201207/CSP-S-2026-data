#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
const int N = 505, M = 500005, Dm = 25, inf = 1e18;
using namespace std;

int c, n, m, D, q;
int g[N][N];
int snum[M], sid[M][Dm], st[M][Dm];
int w[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int ki, ai, ti;
		cin >> ki;
		for (int j = 1; j <= ki; j++) {
			cin >> ai >> ti;
			sid[ai][++snum[ai]] = i;
			st[ai][snum[ai]] = ti;
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = inf;
	for (int i = 1; i <= n; i++)
		g[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= snum[i]; j++) {
			for (int k = j + 1; k <= snum[i]; k++) {
				int a1 = sid[i][j], a2 = sid[i][k];
				g[a1][a2] = min(g[a1][a2], st[i][j] + st[i][k]);
				g[a2][a1] = min(g[a2][a1], st[i][j] + st[i][k]);
			}
		}
	}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	
	for (int t = 1, xi, yi; t <= q; t++) {
		cin >> xi >> yi;
		int ans = inf;
		for (int i = 1; i <= snum[xi]; i++) {
			for (int j = 1; j <= snum[yi]; j++) {
				int a1 = sid[xi][i], a2 = sid[yi][j];
				ans = min(ans, g[a1][a2] + st[xi][i] + st[yi][j]);
			}
		}
		cout << ans + w[xi] + w[yi] << endl;
	}
	return 0;
}
