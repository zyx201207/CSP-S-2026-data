#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510, M = 1000010;
int C, n, m, d, Q, w[M], K[N], f[N][N];
struct tt {
	int x, t;
};
vector <tt> v[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &K[i]);
		for (int j = 1, x, t; j <= K[i]; j++) {
			scanf("%lld%lld", &x, &t);
			v[x].push_back({i, t});
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = j + 1; k < v[i].size(); k++) {
				int x = v[i][j].x, y = v[i][k].x;
				f[x][y] = min(f[x][y], v[i][k].t + v[i][j].t);
				f[y][x] = min(f[y][x], v[i][k].t + v[i][j].t);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k) continue;
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k) continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (Q--) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		if (x == y) {
			printf("0\n");
			continue;
		}
		int res = 1e18;
		for (auto i : v[x]) {
			for (auto j : v[y]) {
				res = min(res, f[i.x][j.x] + i.t + j.t + w[x] + w[y]);
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
