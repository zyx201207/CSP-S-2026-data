#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gc getchar()
#define cs const
#define pf printf
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
inline ll read()
{
	ll sum = 0, f = 1;
	char ch = gc;
	while (ch > '9' || ch < '0')	
	{
		if (ch == '-')
			f = -1;
		ch = gc;
	}
	while (ch >= '0' && ch <= '9')
	{
		sum = 10 * sum + ch - '0';
		ch = gc;
	}
	return sum * f;
} 
#define rd read()

ll cs N = 2e6 + 5;
ll c;
vector<ll> G[N];
vector<ll> x(N + 1);
ll mn = 1e9 + 7, ans = 0;

void dfs(ll now, ll r, ll step)
{
	if (now == r)
	{
		if (step < mn)
		{
			mn = step;
			ans = 1;
		}
		else if (step == mn)
			ans++;
		return ;
	}
	for (int i = 0; i < G[now].size(); i++)
	{
		ll v = G[now][i];
		if (v >= r)
		{
			dfs(r, r, step + 1);
			return;
		}
		dfs(v, r, step + 1);
	}
	return ;
}

void solve()
{
	ll n = rd, d = rd;
	for (int i = 1; i <= n; i++)
	{
		x[i] = rd;
	}
		
	if (c == 11 || c == 12)
	{
		ll d1 = x[2] - x[1];
		ll k = d / d1;
		if(d1 > d || k < 2)
		{
			pf("0\n");
			return ;
		}
		ll ans = n - 2 * k + 1;
		pf("%lld\n", ans);
		return ;
	}
	
	for (int i = 1; i <= n; i++)
	{
		ll dis = 0;
		for (int j = i + 1; j <= n; j++)
		{
			dis = x[j] - x[i];
			if (dis > d)
				break;
			G[i].push_back(j);
		}
	}
	ll as = 0;
	for (int i = 1; i <= n - 3; i++)
	{
		for (int j = i + 3; j <= n; j++)
		{
			dfs(i, j, 0);
			if (ans == 2)
				as++;
			ans = 0;
			mn = 1e9 + 7;
		}
	}
	pf("%lld\n", as);
	for (int i = 1; i <= n; i++)
		G[i].clear();
}

signed main()
{
	fr("migrate.in");
	fw("migrate.out");
	c = rd;
	ll T = rd;
	while (T--)
		solve();
	return 0;
}
