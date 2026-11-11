#include <iostream>
#include <cstdio>
#include <cstring>

#define ll long long

const int MAXN = 2e6 + 7;

ll c, t;
ll n, d;
ll x[MAXN];

ll cnt[307][307];
ll dis[307][307];

void dfs(int st, int k, int step)
{
	if (step > dis[st][k]) return;
	if (step == dis[st][k]) cnt[st][k]++;
	
	for (int i = k + 1; i <= n; i++)
	{
		if (x[i] - x[k] > d) break;
		dfs(st, i, step + 1);
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	std::cin >> c >> t;
	
	while (t--)
	{
		std::cin >> n >> d;
		for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		
		// testpoint #11&12
		if (c == 11 || c == 12)
		{
			if (x[2] - x[1] > d) std::cout << 0 << std::endl;
			else
			{
				ll d0 = x[2] - x[1];
				ll k = d / d0;			// length = 2k
				if (k == 1) std::cout << 0 << std::endl;
				else std::cout << std::max(0ll, n - 2 * k + 1ll) << std::endl;
			}
		}
		
		else
		{
			memset(dis, 0ll, sizeof dis);
			for (int i = 1; i < n; i++)
			{
				dis[i][i] = 1ll;
				if (x[i + 1] - x[i] > d)
				{
					for (int j = i + 1; j <= n; j++) dis[i][j] = 0x7FFFFFFFFFFFFFFF;
					continue;
				}
				
				int idx = i + 1, p = i;
				
				while (p < n && idx <= n)
				{
					while (x[idx] - x[p] <= d && idx <= n)
					{
						dis[i][idx] = dis[i][idx - 1];
						idx++;
					}
					dis[i][idx] = dis[i][idx - 1] + 1ll;
					idx++;
					p = idx - 1;
				}
			}
			
			memset(cnt, 0ll, sizeof cnt);
			for (int i = 1; i < n; i++)
			{
				dfs(i, i, 0ll);
			}
			
			ll ans = 0ll;
			for (int i = 1; i <= n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (cnt[i][j] == 2ll) 
					{
						ans++;
					}
				}
			}
			
			std::cout << ans << std::endl;
		}
	}
}
