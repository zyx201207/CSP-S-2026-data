#include <cstdio>
#include <vector>
#include <algorithm>
using std::min;
using std::max;
#define minx(A, B) (A = min(A, B))

const int MX = 4010;

std::vector <int> T[MX];

namespace solve
{
namespace tr
{
int fa[MX];

void DFS(int u)
{
	for (int v : T[u])
		if (v != fa[u])
			fa[v] = u,
			DFS(v);
}

void init()
{
	DFS(1);
}
}

namespace count
{
using tr::fa;
int ban1, ban2;

namespace dia
{
int deg[MX];
std::vector <int> vv;

void DFS(int u, int fr = 0)
{
	vv.push_back(u);
	deg[u] = 0;
	for (int v : T[u])
		if (v != fr and v != ban1 and v != ban2)
			DFS(v, u), deg[u]++;
}

std::vector <int> get(int n, int u)
{
	std::vector <int> ret(n);
	vv.clear();
	DFS(u);
	static bool in[MX];
	static int dis[MX];
	std::vector <int> q;
	for (int v : vv)
		if (in[v] = true, dis[v] = 0, deg[v] == 1)
			q.push_back(v);
	for (int i = 0; i < q.size(); i++)
	{
		int v = q[i];
		in[v] = false;
		for (int w : T[v])
			if (in[w] and --deg[w] == 1)
				dis[w] = dis[v] + 1,
				q.push_back(w);
	}
	for (int v : vv)
		ret[dis[v]]++;
	return ret;
}
}

int count(int n, int k, int u)
{
	ban1 = u;
	ban2 = fa[u];
	auto v1 = dia::get(n, u), v2 = dia::get(n, fa[u]);
	for (int i = 0; i < n; i++)
		if (max(v1[i], 1) + max(v2[i], 1) <= k)
			return i;
	return MX;
}
}

int solve(int n, int k)
{
	tr::init();
	int ret = MX;
	for (int i = 2; i <= n; i++)
		minx(ret, count::count(n, k, i));
	return ret;
}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int t, n, k;
	scanf("%*d%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1, u, v; i < n; i++)
			scanf("%d%d", &u, &v),
			T[u].push_back(v),
			T[v].push_back(u);
		printf("%d\n", solve::solve(n, k));
		for (int i = 1; i <= n; T[i++].clear());
	}
}