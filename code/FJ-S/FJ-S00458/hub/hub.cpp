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

const ll N = 1e6 + 5, K = 25;
ll c, t, n, k, d[N], f[N][K], kk, ans;
vector<ll> g[N];
bool istag[N];

inline void init()
{
	for(int i = 1; i <= n; i++)
	{
		g[i].clear();
	}
	memset(d, 0, sizeof(d));
	memset(istag, false, sizeof(istag));
	memset(f, 0, sizeof(f));
	ans = 0, d[1] = 1;
}

void dfs(ll u)
{
	for(ll v : g[u])
	{
		if(d[v]) continue;
		d[v] = d[u] + 1;
		f[v][0] = u;
		dfs(v);
	}
}

inline ll dis(ll u, ll v)
{
	ll x = u, y = v, lca;
	if(d[u] > d[v]) swap(u, v);
	for(ll i = kk; i >= 0; i--)
	{
		if(d[f[v][i]] >= d[u])
		{
			v = f[v][i];
		}
	}
	lca = u;
	if(u != v)
	{
		for(ll i = kk; i >= 0; i--)
		{
			if(f[v][i] != f[u][i])
			{
				u = f[u][i], v = f[v][i];
			}
		}
		lca = f[u][0];
	}
	return d[x] - d[lca] + d[y] - d[lca];
}

inline ll solve()
{
	ll res = 0;
	for(ll i = 1; i <= n; i++)
	{
		if(istag[i]) continue;
		for(ll j = 1; j <= n; j++)
		{
			if(!istag[j]) continue;
			res = max(res, dis(i, j));
		}
	}
	return res;
}

void tag(int x, int cnt)
{
	if(cnt == k)
	{
		ans = min(ans, solve());
		return ;
	}
	if(x > n) return;
	istag[x] = 1;
	cnt++;
	tag(x + 1, cnt);
	istag[x] = 0;
	cnt--;
	tag(x + 1, cnt);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		init();
		n = r(), k = r();
		kk = log2(n);
		for(ll i = 1; i <= n - 1; i++)
		{
			ll u = r(), v = r();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= kk; j++)
			{
				f[i][j] = f[f[i][j - 1]][j - 1];
			}
		}
		if(k == 2)
		{
			for(ll i = 1; i <= n; i++)
			{
				for(ll j = 1; j <= n; j++)
				{
					ans = max(ans, dis(i, j));
				}
			}
			cout << ans / k - 1 <<'\n';
		}
		else
		{
			ans = 1e18;
			tag(1, 0);
			cout << ans << '\n';
		}
	}
	return 0;
}
