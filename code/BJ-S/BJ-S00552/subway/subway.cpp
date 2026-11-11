//100 pts
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
const ll PInf = 0x3f3f3f3f3f3f3f3f;
const int MaxN = 5e2;
const int MaxM = 5e5;
const int MaxD = 2e1;

int c, n, m, d, q;
int w[1 + MaxM];
int k, a, t;
int cntedg[1 + MaxM], id[1 + MaxM][1 + MaxD], edgw[1 + MaxM][1 + MaxD];
ll dis[1 + MaxN][1 + MaxN];
int x, y;
ll ans;

void work_q () {
	scanf("%d%d", &x, &y);
	ans = PInf;
	for (int i = 1; i <= cntedg[x]; ++i) {for (int j = 1; j <= cntedg[y]; ++j) {
		int u = id[x][i], wu = edgw[x][i], v = id[y][j], wv = edgw[y][j];
		ans = min(ans, wu + dis[u][v] + wv);
		// printf("%i %i %lld\n", u, v, wu + dis[u][v] + wv);
	}}
	printf("%lld\n", w[x] + ans + w[y]);
}
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) {scanf("%d", &w[i]);}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		for (int j = 1; j <= k; ++j) {
			scanf("%d%d", &a, &t);
			++cntedg[a];
			id[a][cntedg[a]] = i;
			edgw[a][cntedg[a]] = t;
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i) {dis[i][i] = 0;}
	for (int i = 1; i <= m; ++i) {
		for (int id1 = 1; id1 <= cntedg[i]; ++id1) {
			for (int id2 = 1; id2 <= cntedg[i]; ++id2) {
				int u = id[i][id1], wu = edgw[i][id1], v = id[i][id2], wv = edgw[i][id2];
				dis[u][v] = min(dis[u][v], 1ll*(wu + wv));
			}
		}
	}
	for (int mid = 1; mid <= n; ++mid) {
		for (int u = 1; u <= n; ++u) {for (int v = 1; v <= n; ++v) {
			ll newdis = dis[u][mid] + dis[mid][v];
			if (dis[u][v] > newdis) {dis[u][v] = newdis;}
		}}
	}
	while (q--) {work_q();}
	return 0;
}