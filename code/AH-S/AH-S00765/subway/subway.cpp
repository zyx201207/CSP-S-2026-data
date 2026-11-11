#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e2 + 2;
const int M = 5e5 + 2;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, x, y, l[M][22], tot[M];
LL w[M], k[N], dis[N][N], v[N][M];

void Solve() {
	scanf("%d%d", &x, &y);
	LL ans = w[x] + w[y], tmp = LINF;
	for (int i = 1; i <= tot[x]; i++) {
		for (int j = 1; j <= tot[y]; j++) {
			int la = l[x][i], lb = l[y][j];
//			printf("l[%d][%d]=%d/l[%d][%d]=%d\n", x, i, l[x][i], y, j, l[y][j]);
			tmp = min(tmp, v[la][x] + dis[la][lb] + v[lb][y]);
		}
	}
	printf("%lld\n", ans + tmp);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int a;
			LL t;
			scanf("%d%lld", &a, &t);
			l[a][++tot[a]] = i;
			v[i][a] = t;
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= tot[i]; j++) {
			for (int k = 1; k <= tot[i]; k++) {
				int la = l[i][j], lb = l[i][k];
				dis[la][lb] = min(dis[la][lb], v[la][i] + v[lb][i]);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
	while (q--) {
		Solve();
	}
	return 0;
}
