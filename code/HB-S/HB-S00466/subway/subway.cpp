#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using std::min;
#define minx(A, B) (A = min(A, B))
#define INF (intt)1e18
typedef long long intt;

const int MX = 510, MXM = 500010;

std::vector <std::pair <int, int> > v[MXM];
int w[MXM];

namespace solve
{
namespace sp
{
intt dis[MX][MX];

void floyd(int n)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				minx(dis[i][j], dis[i][k] + dis[k][j]);
}

void sp(int n, int m)
{
	for (int i = 1; i <= n; memset(dis[i++] + 1, 0x3f, sizeof(intt) * n));
	for (int i = 1; i <= n; dis[i][i] = 0, i++);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j < v[i].size(); j++)
			for (int k = 0; k < j; k++)
				minx(dis[v[i][j].first][v[i][k].first], (intt)v[i][j].second + v[i][k].second),
				minx(dis[v[i][k].first][v[i][j].first], (intt)v[i][j].second + v[i][k].second);
	floyd(n);
}
}

void init(int n, int m)
{
	sp::sp(n, m);
}

intt query(int x, int y)
{
	intt ret = INF;
	for (auto px : v[x])
		for (auto py : v[y])
			minx(ret, sp::dis[px.first][py.first] + w[x] + w[y] + px.second + py.second);
	return ret;
}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int n, m, q;
	scanf("%*d%d%d%*d%d", &n, &m, &q);
	for (int i = 1; i <= m; scanf("%d", w + i++));
	for (int i = 1, k; i <= n; i++)
	{
		scanf("%d", &k);
		for (int a, t; k--; )
			scanf("%d%d", &a, &t),
			v[a].push_back({ i, t });
	}
	solve::init(n, m);
	for (int x, y; q--; )
		scanf("%d%d", &x, &y),
		printf("%lld\n", solve::query(x, y));
}