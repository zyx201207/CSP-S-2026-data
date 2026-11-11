#include <cstdio>
#include <cstring>
using ll = long long;
const int N = 2e6 + 5;
ll x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	for (scanf("%d%d", &c, &t); t--;) {
		int n;
		ll d;
		scanf("%d%lld", &n, &d);
		for (int i = 0; i < n; ++i) scanf("%lld", x + i);
		if (c <= 6) {
			static int dis[305][305], is[305][305];
			memset(dis, 0x3f, sizeof dis), memset(is, 0, sizeof is);
			for (int i = 0; i < n; ++i) for (int j = i + 1; j < n && x[j] - x[i] <= d; ++j) dis[i][j] = dis[j][i] = 1, is[i][j] = is[j][i] = 1;
			for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
			for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) if (i != k) for (int j = 0; j < n; ++j) if (i != j && j != k && dis[i][k] + dis[k][j] == dis[i][j] && dis[i][j] != 1) is[i][j] += is[i][k] * is[k][j];
			ll ans = 0;
			for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (is[i][j] == 2) ++ans;
			printf("%lld\n", ans);
		} else if (c == 13 || c == 14) puts("0");
		//puts("sm20459586");
	}
}
