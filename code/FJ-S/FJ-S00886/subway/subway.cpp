#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

const long long INF = 1e18 + 10;
const int MSIZE = 5e5 + 10;
struct Subway{
	int station, t;
	Subway(int ss, int tt)
	{
		station = ss, t = tt;
	}
	Subway() {}
};
struct Station{
	int pa, t;
	Station(int pp, int tt)
	{
		pa = pp, t = tt;
	}
	Station() {}
};
int c, n, m, d, q, u, v;
int w[MSIZE] = {0};
bool vis[510] = {0};
long long res;
vector<Station> station[MSIZE];
vector<Subway> path[510];

void dfs(int x, long long cost)
{
	if(cost > res)
	{
		return;
	}
	if(x == v)
	{
		res = min(res, cost);
		return;
	}
	
	int upath;
	for(int i = 0; i < station[x].size(); i++)
	{
		upath = station[x][i].pa;
		if(vis[upath])
		{
			continue;
		}
		
		cost += station[x][i].t;
		vis[upath] = true;
		for(int j = 0; j < path[upath].size(); j++)
		{
			if(path[upath][j].station == x)
			{
				continue;
			}
			dfs(path[upath][j].station, cost + 1LL * path[upath][j].t);
		}
		cost -= station[x][i].t;
		vis[upath] = false;
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &w[i]);
	}
	for(int i = 1, k, ss, tt; i <= n; i++)
	{
		scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			scanf("%d%d", &ss, &tt);
			path[i].push_back(Subway(ss, tt));
			station[ss].push_back(Station(i, tt));
		}
	}
	
	while((q--) > 0)
	{
		scanf("%d%d", &u, &v);
		memset(vis, 0, sizeof(vis));
		res = INF;
		
		dfs(u, 0);
		res += 1LL * w[u] + 1LL * w[v];
		printf("%lld\n", res);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
