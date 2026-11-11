#include<bits/stdc++.h>
using namespace std;
#define pli pair<long long,int> 
const int M = 500010;
const int A = 500510;
int c, n, m, d, q;
long long w[M];
int h[A], nxt[2*A], to[2*A], cnt;
long long t[2*A];
long long tt[A];
void add(int u, int v, int _t)
{
	to[++cnt] = v;
	nxt[cnt] = h[u];
	h[u] = cnt;
	t[cnt] = _t;
}
long long dis[A];
bool vis[A];
void dij(int s, int y)
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<pli,vector<pli>,greater<pli > > q;
	q.push(make_pair(0, s));
	dis[s] = 0;
	while(!q.empty())
	{
		int u = q.top().second; q.pop();
		if(u == y) continue;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u]; i; i = nxt[i])
		{
			int v = to[i];
			if(dis[v] > dis[u] + t[i])
			{
				dis[v] = dis[u] + t[i];
				q.push(make_pair(dis[v], v));
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%lld", w+i);
if(c != 20 && c != 21)
{
	for(int i = 1; i <= n; i++)
	{
		int k, _a;
		long long _t;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			scanf("%d%lld", &_a, &_t);
			add(m+i, _a, _t);
			add(_a, m+i, _t);
		}
	}
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		dij(x, y);
		printf("%lld\n", dis[y] + w[x] + w[y]);			
	}
}
else if(n <= 2)
{
	long long cst = 1LL << 60;
	for(int i = 1; i <= n; i++)
	{
		int k, _a;
		long long _t;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			scanf("%d%lld", &_a, &_t);
			dis[_a] += i;
			if(i == 1) t[_a] = _t;
			else tt[_a] = _t;
			if(dis[_a] == 3) cst = min(cst, t[_a] + _t);	
		}
	}
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		long long ans = 0;
		if(dis[x] == dis[y]) 
		{
			if(dis[x] == 1) ans = t[x] + t[y];
			else if(dis[x] == 2) ans = tt[x] + tt[y];
			else if(dis[x] == 3) ans = min(t[x] + t[y], tt[x] + tt[y]);
		}
		else if(dis[x] == 3)
		{
			if(dis[y] == 1) ans = t[y] + t[x];
			else if(dis[y] == 2) ans = tt[y] + tt[x];
		}
		else if(dis[y] == 3)
		{
			if(dis[x] == 1) ans = t[y] + t[x];
			else if(dis[x] == 2) ans = tt[y] + tt[x];
		}
		else if(dis[x] == 1)
		{
			ans = t[x] + cst + tt[y];
		}
		else if(dis[y] == 1)
		{
			ans = tt[x] + cst + t[y];
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
}
	return 0;
}
