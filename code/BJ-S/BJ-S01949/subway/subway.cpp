#include<cstdio>
#include<algorithm>
#include<cstring>
//bool st;
using LL = long long;
const int N = 505, M = 500005;
int n, m, d, q;
int w[M];
int what[M][20], wcnt[M];
int how[M][20];
LL dis[N][N];
void upd(LL &x, LL a) {
	x = std::min(x, a);
}
//bool en;
int main() {
	//printf("%ld\n", (&en - &st) / 1024 / 1024);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%*d %d %d %d %d", &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int a, t;
			scanf("%d %d", &a, &t);
			what[a][++wcnt[a]] = i;
			how[a][wcnt[a]] = t;
		}
	}

	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i)
		dis[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= wcnt[i]; ++j) {
			for (int k = 1; k <= wcnt[i]; ++k)
				upd(dis[what[i][j]][what[i][k]], (LL)how[i][j] + how[i][k]);
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				upd(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}

	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		LL ans = 1e18;
		for (int i = 1; i <= wcnt[x]; ++i) {
			for (int j = 1; j <= wcnt[y]; ++j)
				upd(ans, dis[what[x][i]][what[y][j]] + how[x][i] + how[y][j]);
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}