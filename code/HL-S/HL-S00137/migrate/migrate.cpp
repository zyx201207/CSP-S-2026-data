#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
struct edge
{
	long long v;
	long long w;	
};
struct point
{
	long long id;
	long long w;	
};
struct cmp
{
	bool operator() (point x, point y) const
	{
		return x.w > y.w;
	}	
};
vector<vector<edge> > b(2000001);
long long dis[2000001];
long long howmany[2000001];
void dijkstra(int p)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(howmany, 0, sizeof(howmany));
	dis[p] = 0;
	howmany[p] = 1;
	priority_queue<point, vector<point>, cmp> q;
	q.push(point({p, 0}));
	while (!q.empty())
	{
		point h = q.top();
		q.pop();
		//printf("%d %d\n", h.id, h.w);
		long long u = h.id;
		for (int i = 0; i < b[u].size(); i ++)
		{
			//printf("894123648931268\n");
			long long v = b[u][i].v, w = b[u][i].w;
			if (dis[u] + w < dis[v])
			{
				//printf("agafiwdbawfig\n");
				dis[v] = dis[u] + w;
				q.push(point({v, dis[v]}));
				howmany[v] = howmany[u];
			}
			else if (dis[u] + w == dis[v])
			{
				howmany[v] += howmany[u];
			}
		}
	}
}
void addedge(int u, int v, int w)
{
	b[u].push_back(edge({v, w}));
	b[v].push_back(edge({u, w}));
}
long long c, t, n, d, x[2000001];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	for (int _ = 1; _ <= t; _ ++)
	{
		b = vector<vector<edge> >(2000001);
		long long ans = 0;
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i ++)
		{
			scanf("%lld", &x[i]);
		}
		for (int i = 1; i < n; i ++)
		{
			for (int j = i + 1; j <= n; j ++)
			{
				if (llabs(x[i] - x[j]) <= d)
				{
					addedge(i, j, 1);
				}
			}
		}
		for (int i = 1; i < n; i ++)
		{
			dijkstra(i);
			for (int j = i + 1; j <= n; j ++)
			{
				if (howmany[j] == 2)
				{
					//printf("(%lld, %lld)\n", i, j);
					ans ++;
				}
			}
		}
		printf("%lld\n", ans);
	}
}