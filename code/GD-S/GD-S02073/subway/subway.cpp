#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5 , M = 505 , inf = 1e18 + 7;
int c , n , m , d , q;
vector <pair <int , int> > S[N];
int f[M][M] , W[N];
signed main ()
{
	freopen ("subway.in" , "r" , stdin);
	freopen ("subway.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++) cin >> W[i];
	for (int i = 1;i <= n;i ++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= k;j ++)
		{
			int u , w;
			cin >> u >> w;
			S[u].push_back ({i , w});
		}
	}
	memset (f , 0x3f , sizeof f);
	for (int i = 1;i <= n;i ++) f[i][i] = 0;
	for (int k = 1;k <= m;k ++)
	{
		int sz = S[k].size ();
		for (int i = 0;i < sz;i ++)
			for (int j = i + 1;j < sz;j ++)
			{
				int u = S[k][i].first , uw = S[k][i].second;
				int v = S[k][j].first , vw = S[k][j].second;
				f[u][v] = f[v][u] = min (f[u][v] , uw + vw);
			}
	}
	for (int k = 1;k <= n;k ++)
		for (int i = 1;i <= n;i ++)
			for (int j = 1;j <= n;j ++)
				f[i][j] = min (f[i][k] + f[k][j] , f[i][j]);
	while (q --)
	{
		int u , v;
		cin >> u >> v;
		if (u == v) cout << "0\n";
		else
		{
			int ans = inf;
			for (auto it1 : S[u])
				for (auto it2 : S[v])
				{
					int x = it1.first , uw = it1.second;
					int y = it2.first , vw = it2.second;
					ans = min (ans , f[x][y] + uw + vw);
				}
			cout << ans + W[u] + W[v] << '\n';
		}
	}
	return 0;
}
