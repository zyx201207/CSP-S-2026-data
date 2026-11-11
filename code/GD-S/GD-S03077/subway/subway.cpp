#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500 + 7;
const int M = 5e5 + 7;

int c, n, m, d, q;

int w[M];

vector<pair<int, ll> > e[M];

ll dis[N][N];

//ll val[N][M];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin.tie(0) -> ios::sync_with_stdio(false);
	
//	cout << "E" << endl;
	
	memset(dis, 0x3f, sizeof dis);
//	memset(val, 0x3f, sizeof val);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i(1); i <= m; ++i)
		cin >> w[i];
		
	for(int i(1); i <= n; ++i)
	{
		int k;
		cin >> k;
		
		
		for(int j(1); j <= k; ++j)
		{
			
			int a;
			ll t;
			
			cin >> a >> t;
			
			e[a].emplace_back(i, t);
		}
	}
	
	for(int i(1); i <= n; ++i)
		dis[i][i] = 0;
	
	for(int i(1); i <= m; ++i)
	for(int j(0); j < e[i].size(); ++j)
	for(int k(j + 1); k < e[i].size(); ++k)
	{
		dis[e[i][k].first][e[i][j].first] = dis[e[i][j].first][e[i][k].first] = min(dis[e[i][j].first][e[i][k].first], e[i][j].second + e[i][k].second);
	}
	
	for(int k(1); k <= n; ++k)
	for(int i(1); i <= n; ++i)
	for(int j(i + 1); j <= n; ++j)
	{
		if(dis[i][k] == dis[0][0] || dis[k][j] == dis[0][0])continue;
		dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	
//	for(int i(1); i <= n; ++i)
//	for(int j(1); j <= n; ++j)
//	cout << dis[i][j] << " \n"[j == n];
	
//	for(int i(1); i <= m; ++i)
//	for(const auto &v : e[i])
//	for(int j(1); j <= n; ++j)
//	{
//		if(dis[v.first][j] == dis[0][0])continue;
//		val[j][i] = min(val[j][i], v.second + dis[v.first][j]);
//	}
//	
	
	for(int i(1); i <= q; ++i)
	{
		int u, v;
		
		cin >> u >> v;
		
		ll ans = 1e18;
		
		for(const auto &j : e[u])
		for(const auto &k : e[v])
		{
			ans = min(ans, dis[j.first][k.first] + j.second + k.second);
		} 
		
		cout << ans + w[u] + w[v] << '\n';
	}
	
	return 0;	
} 
