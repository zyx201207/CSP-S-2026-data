#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn = 505, maxk = 2e4 + 5, maxm = 2e4 + 5, INF = (LL)1e18, maxd = 25;
LL C, n, m, d, q;
struct Line
{
	LL a, t;
};
struct subway
{
	LL k, a[maxk];
}line[maxn];
LL w[maxm], t[maxm][maxn];
vector <LL> bl[maxm];
struct whole
{
	LL ting, xian, c;
};
LL dis[maxm];
LL vis[maxm][maxn];
LL sum[maxm], nd[maxn];
void bfs(LL s)
{
	whole u;
	int v;
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= m; i++) dis[i] = INF;
	queue <whole> q;
	dis[s] = 0;
	for(LL i : bl[s])
		q.push({s, i, t[s][i]});
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		if(vis[u.ting][u.xian] == nd[u.xian]) continue;
		vis[u.ting][u.xian]++;
//		cout << u.ting << ' ' << u.xian << ' ' << u.c << '\n';
		for(int i = 1; i <= line[u.xian].k; i++)
		{
			v = line[u.xian].a[i];
			if(v == u.ting) continue;
			q.push({v, u.xian, u.c + t[v][u.xian]});
			dis[v] = min(dis[v], u.c + t[v][u.xian]);
		}
		for(int i : bl[u.ting])
		{
			q.push({u.ting, i, u.c + t[u.ting][i]});
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	scanf("%lld%lld%lld%lld%lld", &C, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &line[i].k);
		for(int j = 1; j <= line[i].k; j++)
		{
			scanf("%lld", &line[i].a[j]);
			scanf("%lld", &t[line[i].a[j]][i]);
			sum[line[i].a[j]]++;
			bl[line[i].a[j]].push_back(i);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= line[i].k; j++)
			nd[i] += sum[line[i].a[j]];
//		nd[i] -= line[i].k;
	}
	LL x, y;
	while(q--)
	{
		scanf("%lld%lld", &x, &y);
		bfs(x);
		printf("%lld\n", dis[y] + w[x] + w[y]);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
