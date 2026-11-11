//GZ-S00247 遵义市第四中学 翁铭卓 
#include <cstdio>
#include <bitset>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
const int M = 5e5 + 10, N = 500;

int c, n, m, d, q;
vector<pii> g[M + N];
bitset<M + N> vis;
ll dist[M + N], w[M];

template<typename T> inline void write(T x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

void init()
{
	memset(dist, 0x3f3f3f3f, sizeof dist);
	vis.reset();
}

void dijkstra(int st)
{
	dist[st] = 0;
	
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, st});
	
	int cnt = 0;
	while (q.size())
	{
		int u = q.top().y;
		q.pop();
		if (vis[u] == 1)
			continue;
			
		vis[u] = 1;
		for (int i = 0; i < g[u].size(); i ++ )
		{
			int j = g[u][i].y;
			if (dist[j] > dist[u] + g[u][i].x)
			{
				dist[j] = dist[u] + g[u][i].x;
				q.push({dist[j], j});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++ )
		scanf("%lld", &w[i]);
	
	for (int i = 1; i <= n; i ++ )
	{
		int k, a;
		ll t;
		scanf("%d", &k);
		for (int j = 1; j <= k; j ++ )
		{
			scanf("%d%lld", &a, &t);
			g[a].push_back({t, m + i});
			g[m + i].push_back({t, a});
		}
	}
			
	int st, ed;
	while (q -- )
	{
		init();
		scanf("%d%d", &st, &ed);
		dijkstra(st);
		write(dist[ed] + w[st] + w[ed]), puts("");
	}
	
	return 0;
}
