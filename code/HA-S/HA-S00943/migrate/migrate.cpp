#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c, t;
ll n, d;
ll x[2000060], dis[6050][6050], mi[6050][6050];
void dfs(ll zx, ll u)
{
	ll re = 0;
	for(ll i = u + 1; i <= u + d && i <= n; i++)
	{
		if(x[i] - x[u] <= d)
		{
			ll s = mi[zx][u] + 1;
			if(s == mi[zx][i])
			{
				dis[zx][i]++;
				dfs(zx, i);
			}
			else if(s < mi[zx][i])
			{
				dis[zx][i] = 1;
				mi[zx][i] = s;
				dfs(zx, i);
			}else
			continue;
			
		}
		else
		{
			return ;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		ll ans = 0;
		memset(dis, 0, sizeof dis);
		memset(mi, 0x3f, sizeof mi);
		cin >> n >> d;
		for(ll i = 1; i <= n; i++)
		{
			cin >> x[i];
			mi[i][i] = 0;
		}
		for(ll i = 1; i < n; i++)
		{
			dfs(i, i);
		}
		for(ll i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(dis[i][j] == 2)
				{
					ans++;
				}
				
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
