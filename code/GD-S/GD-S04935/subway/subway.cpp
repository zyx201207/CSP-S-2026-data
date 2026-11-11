#include <stdio.h>
#include <string.h>
#include <vector>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define INF 0x3F3F3F3F3F3F3F3FLL
typedef long long int llong;
int c, n, m, d, q;
llong w[500005];
std::vector <std::pair <int, int> > p[500005];
llong dis[505][505];
int main (void) {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i)	scanf ("%lld", &w[i]);
	for (int i = 1, k; i <= n; ++i) {
		scanf ("%d", &k);
		for (int j = 1, a, t; j <= k; ++j) {
			scanf ("%d %d", &a, &t);
			p[a].push_back ({i, t});
		}
	}
	memset (dis, 0x3F, sizeof (dis));
	for (int i = 1; i <= n; ++i)	dis[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < p[i].size (); ++j) {
			for (int l = 0; l < p[i].size (); ++l) {
				if (p[i][j].first != p[i][l].first) {
					int u = p[i][j].first, v = p[i][l].first;
					llong w = (llong)p[i][j].second + (llong)p[i][l].second;
					dis[u][v] = min (dis[u][v], w);
					dis[v][u] = min (dis[v][u], w);
				}
			}
		}
	}
	for (int l = 1; l <= n; ++l) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i != j && j != l && l != i)	dis[i][j] = min (dis[i][j], dis[i][l] + dis[l][j]);
			}
		}
	}
	for (int r = 1, x, y; r <= q; ++r) {
		scanf ("%d %d", &x, &y);
		llong ans = INF;
		for (int i = 0; i < p[x].size (); ++i) {
			for (int j = 0; j < p[y].size (); ++j) {
				int u = p[x][i].first, v = p[y][j].first;
				llong w = (llong)p[x][i].second + (llong)p[y][j].second;
				ans = min (ans, dis[u][v] + w);
			}
		}
		printf ("%lld\n", ans + w[x] + w[y]);
	}
	
	return 0;
}
