#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define pb push_back

constexpr ll N = 3e3;

ll n, k;
ll a[N + 10];
bool used[N + 10];
bool mp[N + 10][N + 10];
vector<ll> g[N + 10];
ll fa[N + 10];
bool f[N + 10];

ll find(ll u)
{
	if (fa[u] == u)
	{
		return u;
	}
	return fa[u] = find(fa[u]);
}

void dfs1(ll u, ll f)
{
	
}

ll calc()
{
	for (ll i = 1; i <= k; i++)
	{
		for (ll j = i + 1; j <= k; j++)
		{
			ll u = a[i], v = a[j];
			f[u] = 1;
			if (mp[u][v])
			{
				g[u].pb(v);
				g[v].pb(u);
				ll fu = find(u), fv = find(v);
				if (fu != fv)
				{
					fa[fv] = fu;
				}
			}
		}
	}
	ll cnt = 0;
	for (ll i = 1; i <= k; i++)
	{
		ll u = a[i];
		if (find(u) == u)
		{
			cnt++;
			dfs1(i, 0);
		}
	}
	if (cnt > 2)
	{
		return INF;
	}

}

void dfs(ll step)
{
	if (step == k + 1)
	{
		for (ll i = 1; i <= n; i++)
		{
			g[i].clear();
			fa[i] = i;
		}
		calc();
		return ;
	}
	for (ll i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			used[i] = 1;
			a[step] = i;
			dfs(step + 1);
			used[i] = 0;
		}
	}
}

void solve()
{
	cin >> n >> k;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			mp[i][j] = 0;
		}
	}
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		mp[u][v] = mp[v][u] = 1;
	}
	dfs(1);
}

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c, t;
	cin >> c >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

