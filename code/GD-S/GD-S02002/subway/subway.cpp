#include <bits/stdc++.h>
using namespace std;

const int N = 510, M = 5e5 + 10;
struct info {
	int v, w;
	info(int _v = 0, int _w = 0) {
		v = _v, w = _w;
	}
};
int c, n, m, d, q, w[M];
long long a[N][N];
vector<info> te[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k, a, t;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d%d", &a, &t);
			te[a].push_back(info(i, t));
		}
	}
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		a[i][i] = 0;
	} 
	for (int i = 1; i <= m; i++) {
		int len = te[i].size();
		for (int j = 0; j < len; j++) {
			for (int k = j + 1; k < len; k++) {
				int x = te[i][j].v, y = te[i][k].v;
				a[x][y] = min(a[x][y], 0LL + te[i][j].w + te[i][k].w);
				a[y][x] = min(a[y][x], 0LL + te[i][j].w + te[i][k].w);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}
	while (q--) {
		int x, y;
		long long ans = 1LL << 60;
		scanf("%d%d", &x, &y);
		for (auto i : te[x]) {
			for (auto j : te[y]) {
				ans = min(ans, a[i.v][j.v] + i.w + j.w);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	
	return 0; 
}
