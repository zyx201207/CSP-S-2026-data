#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e5 + 10;

ll c, n, m, d, q;

ll ans = 0x3f3f3f;
ll res;
ll fa[N];
ll k[N];
ll w[N];
ll x[N];
ll y[N];

ll chain[501][50001] = {0};
ll a[501][50001] = {0};
ll dp[501][50001];
ll t[501][50001];

inline int read() 
{
	int x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') 
	{
		if (ch == '-') 
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') 
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x * f;
}

ll dfs(ll l, ll x, ll y) 
{
	ll a = t[l][x] + t[l][y] + w[y];
	return a;
}

int main() 
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	memset(dp, 0x3f, sizeof(dp));
	
	for (int i = 1; i <= m ; i++ ) 
	{
		w[i] = read();
	}
	for (int i = 1; i <= n; i ++ ) 
	{
		k[i] = read();
		for (int j = 1; j <= k[i]; j ++ ) 
		{
			a[i][j] = read();
			t[i][j] = read();
			chain[i][a[i][j]] = 1;
		}
	}
	
	for (int i = 1; i <= q; i ++ ) 
	{
		x[i] = read(); 
		y[i] = read();
	}
	
	for (int i = 1; i <= q; i ++ )
	{
		res = w[x[i]];
		for (int j = 1; j <= n; j ++ ) 
		{
			if (chain[j][x[i]] != 0 && chain[j][y[i]] != 0) 
			{
				res += dfs(j, x[i], y[i]);
				ans = min(ans, res);
			}
			else 
			{
				for (int l = 1; l <= m; l ++ ) 
				{
					if (chain[j][x[i]] != 0 && chain[j][l] != 0) 
					{
						ans += min(dfs(j, x[i], l) + dfs(j, l, y[i]), ans);
					}
				}
			}
		}
		cout << ans << endl;
	}
	
}
