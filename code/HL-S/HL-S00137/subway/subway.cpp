#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int w[500001];
int a[501][20001], t[501][20001];
int k[501];
int c, n, m, d, q;
struct edge
{
	int v;
	int w;	
};
struct point
{
	int id;
	int w;	
};
struct cmp
{
	bool operator() (point x, point y) const
	{
		return x.w > y.w;
	}	
};
vector<edge> b[500001];
int dis[500001];
void dijkstra(int p)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[p] = 0;
	priority_queue<point, vector<point>, cmp> q;
	q.push(point({p, 0}));
	while (!q.empty())
	{
		point h = q.top();
		q.pop();
		//printf("%d %d\n", h.id, h.w);
		int u = h.id;
		for (int i = 0; i < b[u].size(); i ++)
		{
			//printf("894123648931268\n");
			int v = b[u][i].v, w = b[u][i].w;
			if (dis[u] + w < dis[v])
			{
				//printf("agafiwdbawfig\n");
				dis[v] = dis[u] + w;
				q.push(point({v, dis[v]}));
			}
		}
	}
}
void addedge(int u, int v, int w)
{
	b[u].push_back(edge({v, w}));
	b[v].push_back(edge({u, w}));
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j ++)
		{
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= k[i]; j ++)
		{
			//printf("addedge: %d <--(%d)--> %d\n", a[i][j], t[i][j], a[i][j] + m * i);
			addedge(a[i][j], a[i][j] + m * i, t[i][j]);
		}
		for (int j = 2; j <= k[i]; j ++)
		{
			//printf("addedge: %d <--(0)--> %d\n", a[i][j] + m * i, a[i][j - 1] + m * i);
			addedge(a[i][j] + m * i, a[i][j - 1] + m * i, 0);
		}
	}
	for (int i = 1; i <= q; i ++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		//printf("%d %d <--\n", x, y);
		//printf("%d <--\n", b[x].size());
		dijkstra(x);
		printf("%d\n", w[x] + dis[y] + w[y]);
	}
}