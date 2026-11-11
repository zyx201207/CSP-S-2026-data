#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

ll c, n, m, d, q;
ll w[500005];

ll k;
ll a[500005];
ll t[500005];
map<pair<ll,ll>, ll> mp;

void build()
{
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i == j) continue;
			pair<ll, ll> path = {a[i], a[j]};
			if (mp.find(path) != mp.end())
			{
				mp[path] = min(mp[path], t[i] + t[j]);
			}
			else mp[path] = t[i] + t[j];
		}
	}
}

ll dis[305][305];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> a[i] >> t[i];
		}
		build();
	}
		
	if (1 <= c && c <= 6)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == j) dis[i][j] = 0;
				else if (mp.find({i, j}) != mp.end()) dis[i][j] = mp[{i, j}];
				else dis[i][j] = 1e18;
			}
		}
		
		for (int t = 1; t <= m; t++)
		{
			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					for (int k = 1; k <= m; k++)
					{
						if (dis[i][k] != 1e18 && dis[k][j] != 1e18) 
						{
							dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//							cout << "一次组合：" << i << " " << k << " " << j << " " << dis[i][j] << '\n'; 
						}
					}
				}
			}
		}

		for (int i = 1; i <= q; i++)
		{
			ll a, b;
			cin >> a >> b;
			cout << dis[a][b] + w[a] + w[b] << '\n';
		}
	}
	
//	if (12 <= c && c <= 19)
//	{
//			
//	}	

//	if (7 <= c && c <= 11)
//	{
//		
//	}
	return 0; 
}

