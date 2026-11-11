#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 1e6 + 10;
int w[M], c, n, m, d, q, k[N];
vector<pair<int, int> > v[M];
long long f[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(f, 0x3f, sizeof f);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = 0;
		scanf("%d", &k[i]);
		for (int x, y, j = 1; j <= k[i]; j++) {
			scanf("%d%d", &x, &y);
			v[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= m; i++) {
		int len = v[i].size();
		for (int x = 0; x < len; x++) {
			for (int y = x+1; y < len; y++) {
				int xa = v[i][x].first, ya = v[i][y].first, wx = v[i][x].second, wy = v[i][y].second;
				f[xa][ya] = min(f[xa][ya], 1LL * wx + wy);
				f[ya][xa] = min(f[ya][xa], 1LL * wx + wy);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		int lenx = v[x].size(), leny = v[y].size();
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 0; i < lenx; i++) {
			for (int j = 0; j < leny; j++) {
				int xa = v[x][i].first, ya = v[y][j].first, wx = v[x][i].second, wy = v[y][j].second;
				ans = min(ans, f[xa][ya] + wx + wy);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
