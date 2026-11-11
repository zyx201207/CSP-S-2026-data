#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int dis[505][505];
int c, n, m, d, q, w[N];
vector<pair<int, int>> a[500005];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++ )
		scanf("%lld", &w[i]);
	for(int i = 1, k; i <= n; i ++ )
	{
		scanf("%lld", &k);
		for(int j = 1; j <= k; j ++ )
		{
			int aa, tt;
			scanf("%lld%lld", &aa, &tt);
			a[aa].push_back({i, tt});
		}
	}
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++ )
		{
			dis[i][j] = 1e18;
 			if(i == j)
 				dis[i][j] = 0;
		}
		
	for(int i = 1; i <= m; i ++ )
	{
		int kk = a[i].size();
		for(int j = 0; j < kk; j ++ )
		{
			int ss = a[i][j].first;
			for(int k = 0; k < j; k ++ )
			{
				int tt = a[i][k].first;
				dis[ss][tt] = min(dis[ss][tt], a[i][j].second + a[i][k].second);
				dis[tt][ss] = dis[ss][tt];
			}
		}
	}
	
	for(int k = 1; k <= n; k ++ )
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= n; j ++ )
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				
	
	for(int i = 1; i <= q; i ++ )
	{
		int x, y;
		scanf("%lld%lld", &x, &y);
		int kk = a[x].size(), kk1 = a[y].size();
		int ans = 1e18;
		for(int j = 0; j < kk; j ++ )
			for(int k = 0; k < kk1; k ++ )
				ans = min(ans, dis[a[x][j].first][a[y][k].first] + a[x][j].second + a[y][k].second);
		cout << ans + w[x] + w[y] << '\n';  
	}
	return 0;
}
