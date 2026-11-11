#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e3 + 1, M = 5e2 + 1;
int c, n, m, d, q, r;
ll T, w[N], a[M][N], t[M][N], f[M][M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int i, j, k, u, v;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	memset(f, 0x3f, sizeof(f));
	for (i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &r);
		for (j = 1; j <= r; j++) {
			scanf("%lld%lld", &a[i][j], &T);
			t[i][a[i][j]] = T;
			for (k = 1; k < j; k++) {
				f[a[i][j]][a[i][k]] = f[a[i][k]][a[i][j]] = t[i][a[i][j]] + t[i][a[i][k]];
			}
		}
	}
	
	for (i = 1; i <= m; i++) {
		f[i][i] = 0;
		for (j = 1; j <= m; j++) {
			if (i == j) {
				continue;
			}
			for (k = 1; k <= m; k++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			} 
		}
	}
	
	while (q--) {
		scanf("%d%d", &u, &v);
		printf("%lld\n", f[u][v] + w[u] + w[v]);
	}
	return 0;
} 
