#include <stdio.h>
typedef long long ll;
constexpr int maxn = 5e2 + 10, maxm = 5e5 + 10, maxd = 25;constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[maxm], k[maxn], tot[maxm], f[maxm][maxd][2];
ll dis[maxn][maxn];
inline ll min(ll x, ll y) {return x < y ? x : y;}
int main()
{
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1;i <= m;i++) scanf("%d", &w[i]);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d", &k[i]);
		for (int j = 1, x, y;j <= k[i];j++) scanf("%d%d", &x, &y), f[x][++tot[x]][0] = i, f[x][tot[x]][1] = y;
	}
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) if (i != j) dis[i][j] = inf;
	for (int i = 1;i <= m;i++)
		for (int u = 1;u <= tot[i];u++)
			for (int v = u + 1;v <= tot[i];v++)
				dis[f[i][u][0]][f[i][v][0]] = dis[f[i][v][0]][f[i][u][0]] = min(dis[f[i][u][0]][f[i][v][0]], f[i][u][1] + f[i][v][1]);
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1, x, y;i <= q;i++)
	{
		scanf("%d%d", &x, &y);
		ll ans = inf;
		for (int u = 1;u <= tot[x];u++)
			for (int v = 1;v <= tot[y];v++)
				ans = min(ans, dis[f[x][u][0]][f[y][v][0]] + f[x][u][1] + f[y][v][1]);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
