#include <stdio.h>
#include <string.h>
int min(int x, int y) {
	return x < y ? x : y;
}
#define FileIO(str) freopen(str".in", "r", stdin); freopen(str".out", "w", stdout);
int c, n, m, d, q, w[500001], k, a, t, head[500501], nxt[1001001], to[1001001], val[1001001], ecnt, x, y, f[501][501], tt[501][500001];
void add(int u, int v, int w) {
	nxt[++ecnt] = head[u];
	to[ecnt] = v;
	val[ecnt] = w;
	head[u] = ecnt;
}
int main() {
//	freopen("subway1.in", "r", stdin); 
	FileIO("subway");
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &w[i]);
		for (int j = 1; j <= m; ++j) {
			if (i == j) {
				f[i][j] = 0;
			}
			else {
				f[i][j] = 0x3f3f3f3f;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		for (int j = 1; j <= k; ++j) {
			scanf("%d%d", &a, &t);
			tt[a][i] = t;
//			add(i + n, a, t);
//			printf("%d->%d linked(val:%d)\n", a, i, t);
			add(a, i + n, t);
		} 
	}
	for (int k = 1; k <= m; ++k) {
		for (int i = head[k]; i; i = nxt[i]) {
			for (int j = head[k]; j; j = nxt[j]) {
				int u = to[i] - n, v = to[j] - n;
				if (i == j) {
					f[u][v] = 0;
					continue;
				}
				f[u][v] = min(f[u][v], val[i] + val[j]);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) {
					continue; 
				}
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		scanf("%d%d", &x, &y);
		int ans = 2147483647;
		for (int i = head[x]; i; i = nxt[i]) {
			for (int j = head[y]; j; j = nxt[j]) {
				int u = to[i] - n, v = to[j] - n;
				ans = min(f[u][v] + tt[x][u] + tt[y][v], ans);
//				printf("UPD: %d->%d\n", u, v);
			}
		}
		printf("%d\n", w[x] + w[y] + ans);
	} 
}
