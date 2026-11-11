#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll c, n, m, d, p, w[500005], k, a, t, x, y;
ll cnt, head[500505], dis[505][505], ans;
struct Edge
{
	ll v, w, next;
} e[1000005];
void add(ll u, ll v, ll w)
{
	cnt++;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> a >> t;
			add(a, i, t);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i != j)dis[i][j] = 1e17;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = head[i]; j; j = e[j].next)
		{
			for(int k = head[i]; k; k = e[k].next)
			{
				if(j == k)continue;
				dis[e[j].v][e[k].v] = min(dis[e[j].v][e[k].v], e[j].w + e[k].w);
			}
		}
//		if(i==50)return 0;
//		cout<<i<<' ';
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
	}
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i == k)continue;
			for(int j = 1; j <= n; j++)
			{
				if(i == j || j == k)continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(p--)
	{
		cin >> x >> y;
		ans = 1e17;
		for(int i = head[x]; i; i = e[i].next)
		{
			for(int j = head[y]; j; j = e[j].next)
			{
				ans = min(ans, e[i].w + e[j].w + dis[e[i].v][e[j].v]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}

