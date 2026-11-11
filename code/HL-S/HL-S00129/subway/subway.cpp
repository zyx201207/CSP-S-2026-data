#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair <LL, int> PLI;

const int N = 510, M = 500010;

int c, n, m, d, q;
int g[M];
int h[N + M], e[20 * M], ne[20 * M], w[20 * M], idx;
LL dist[N + M];
bool st[N + M];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

void dijkstra(int S)
{
	memset(st, 0, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	priority_queue <PLI, vector<PLI>, greater<PLI> > heap;
	dist[S] = 0;
	heap.push({0, S});
	while (heap.size())
	{
		int t = heap.top().second;
		heap.pop();

		if (st[t]) continue;
		st[t] = true;

		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				heap.push({dist[j], j});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++ ) scanf("%d", &g[i]);

	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i ++ )
	{
		int k;
		scanf("%d", &k);
		int p = m + i;
		for (int j = 1; j <= k; j ++ )
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(p, x, y);
			add(x, p, y);
		}
	}

	while (q -- )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		dijkstra(x);
		printf("%lld\n", g[x] + dist[y] + g[y]);
	}

	return 0;
}

