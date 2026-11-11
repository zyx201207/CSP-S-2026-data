#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

inline ll r()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void wt(ll x)
{
	if(x > 9) wt(x / 10);
	putchar((x % 10) + 48);
}

typedef long long ll;
typedef pair<ll, ll> P;
const ll N = 505, M = 5e5 + 5;
const ll MAX = 4557430888798830399;
ll c, n, m, d, q, w[M], dis[M], ans;
vector<P> line[N], bel[N];

void dfs(ll u, ll e, ll t, ll l)
{
//	cout << u <<'\n';
	if(u == e)
	{
		return ;
	}
	for(P to : line[l])
	{
		int v = to.first, w = to.second;
		if(dis[v] != MAX || u == v) continue;
//		cout<<'\t'<<v<<'\n';
		dis[v] = t + w;
		for(P L : bel[v])
		{
			if(L.first != l)
			dfs(v, e, dis[v] + L.second, L.first);
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = r(), n = r(), m = r(), d = r(), q = r();
	for(ll i = 1; i <= m; i++)
	{
		w[i] = r();
	}
	for(ll i = 1; i <= n; i++)
	{
		ll l = r();
		for(ll j = 1; j <= l; j++)
		{
			ll a = r(), t = r();
			line[i].push_back({a, t});
			bel[a].push_back({i, t});
		}
	}
	while(q--)
	{
		ans = 1e18;
		ll x = r(), y = r();
		for(P l : bel[x])
		{
			memset(dis, 0x3f, sizeof(dis));
			dis[x] = w[x] + w[y] + l.second;
			dfs(x, y, w[x] + w[y] + l.second, l.first);
			ans = min(ans, dis[y]);
		}
		wt(ans);
		putchar('\n');
	}
	return 0;
}
