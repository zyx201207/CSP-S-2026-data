#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long, int>
#define st first
#define nd second
const int M = 5e5 + 5, N = 505;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
long long w[M], dis[N][N];
struct node { int a; long long t; };
vector<node> e[N], g[M];

void build()
{
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
		if(dis[i][j] != INF) e[i].push_back({j, dis[i][j]});
	return;
}

void sb(int s)
{
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0ll, s}); dis[s][s] = 0ll;
	while(!q.empty())
	{
		pii u = q.top(); q.pop();
		for(node k : e[u.nd])
		{
			int a = k.a, t = k.t;
			if(t + dis[s][u.nd] < dis[s][a])
			{
				dis[s][a] = k.t + dis[s][u.nd];
				q.push({dis[s][a], a}); 
			}
		}
	}
	return;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for(int i = 1; i <= n; i++)
	{
		int k, a; long long t; scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			scanf("%d%lld", &a, &t);
			g[a].push_back({i, t});
		}
	}
	memset(dis, INF, sizeof(dis));
	for(int i = 1; i <= m; i++)
	{
		for(node u : g[i]) for(node v : g[i])
		{
			if(u.a == v.a) { dis[u.a][v.a] = 0ll; continue; }
			dis[u.a][v.a] = min(dis[u.a][v.a], u.t + v.t);
		}
	}
	build();
	memset(dis, INF, sizeof(dis));
	for(int i = 1; i <= n; i++) sb(i);
	while(q--)
	{
		int x, y; scanf("%d%d", &x, &y);
		long long ans = INF;
		for(node u : g[x]) for(node v : g[y])
			ans = min(ans, dis[u.a][v.a] + u.t + v.t);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
/*

17：35
考校的机子好慢啊，实测本地4e8跑了12s，但复杂度似乎正确？ 
O(nk+md^2+n^2log(n)+qd^2)
不会卡常呜呜呜…… 
千万别卡我！！！ 千万别卡我！！！ 千万别卡我！！！ 千万别卡我！！！ 千万别卡我！！！
卡我的sm！！！ 卡我的sm！！！ 卡我的sm！！！ 卡我的sm！！！ 卡我的sm！！！
能上CSPS迷惑行为大赏吗？……………… 

*/











