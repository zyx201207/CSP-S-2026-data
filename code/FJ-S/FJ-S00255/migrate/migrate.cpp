#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e6 + 10;
int c, t, n;
LL d, x[N];
int head[N], to[N << 1], ne[N << 1], idx;
int dist[N], cnt[N];

void add(int a, int b)
{
	to[idx] = b;
	ne[idx] = head[a];
	head[a] = idx ++;
}

void dijkstra(int s)
{
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	priority_queue<PII, vector<PII>, greater<PII>> q;
	dist[s] = 0, cnt[s] = 0;
	q.push({0, s});
	while(q.size())
	{
		int u = q.top().first;
		q.pop();
		for(int i = head[u]; ~i; i = ne[i])
		{
			int v = to[i];
			if(dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				cnt[v] = 1;
				q.push({dist[v], v});
			}
			else if(dist[v] == dist[u] + 1)
				cnt[v] ++;
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while(t --)
	{
		memset(head, -1, sizeof head);
		
		scanf("%d%lld", &n, &d);
		for(int i = 1;i <= n; ++ i)
			scanf("%lld", &x[i]);
		
		for(int i = 1;i <= n; ++ i)
			for(int j = i + 1;j <= n; ++ j)
				if(x[j] - x[i] > d) break;
				else add(i, j);
		
		LL ans = 0; 
		for(int i = 1;i <= n; ++ i)
		{
			dijkstra(i);
			for(int j = 1;j <= n; ++ i)
				if(cnt[j] == 2)
					ans ++;
		}
		printf("%lld\n", ans);
	}
	return 0; 
}
