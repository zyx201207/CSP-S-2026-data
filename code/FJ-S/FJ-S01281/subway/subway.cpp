#include <iostream>
#include <queue>
#include <vector>

namespace preFile
{
	void init()
	{
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
}

typedef long long ll;
const int maxn = 503;
const int maxm = 5e5 + 3;
const int maxd = 23;
const ll inf = 1e18;
int n, m, d, q, w[maxm];
ll f[maxn][maxn];
struct edge { int to, w; };
std::vector<edge> g[maxm];

int main()
{
	preFile::init();
	int c; std::cin >> c;
	std::cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) std::cin >> w[i];
	for (int i = 1, k; i <= n; i++)
	{
		std::cin >> k;
		for (int j = 1, v, t; j <= k; j++)
		{
			std::cin >> v >> t;
			g[v].push_back({ i, t });
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = inf;
	for (int i = 1; i <= m; i++) for (auto t1 : g[i]) for (auto t2 : g[i])
		f[t1.to][t2.to] = f[t2.to][t1.to] = std::min(f[t1.to][t2.to], (ll)t1.w + t2.w);
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	while (q--)
	{
		int x, y; std::cin >> x >> y;
		ll ans = inf;
		for (auto t1 : g[x]) for (auto t2 : g[y]) ans = std::min(ans, t1.w + t2.w + f[t1.to][t2.to]);
		std::cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
