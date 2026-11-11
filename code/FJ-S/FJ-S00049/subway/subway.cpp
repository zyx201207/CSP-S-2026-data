#include <bits/stdc++.h>

#define x first
#define y second 
#define int long long

using namespace std;

const int N = 510;
const int M = 5e5 + 10;

int c, n, m, d, q;
int w[M];//从地铁口到站厅的时间 
int f1[N], f2[N];
vector<pair<int, int>> tmp[M]; // 第i个站点的所有线路的编号以及站厅到线路的时间
vector<int> Tmp[N]; // 第i个线路的所有经过的站点 
int dist[N][N];//表示路线i到路线j的最小花费 

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++ ) cin >> w[i];
	for(int i = 1 ; i <= n ; i ++ )
	{
		int k;
		cin >> k;
		while(k -- )
		{
			int a, t;
			cin >> a >> t;
			Tmp[i].emplace_back(a);
			tmp[a].push_back({i, t});
		}
	}
	memset(dist, 0x3f3f3f3f, sizeof dist);
	
	for(int i = 1 ; i <= m ; i ++ )
		for(auto u : tmp[i])
			for(auto v : tmp[i])
				if(u.x != v.x)
					dist[u.x][v.x] = min(dist[u.x][v.x], u.y + v.y);
	

	for(int k = 1 ; k <= n ; k ++ )
		for(int i = 1 ; i <= n ; i ++ )
			for(int j = 1 ; j <= n ; j ++ )
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]); 
	
	for(int i = 1 ; i <= n ; i ++ ) dist[i][i] = 0;
	
	while(q -- )
	{
		int l, r;
		cin >> l >> r;
		int ans = 1e18;
		for(int i = 0 ; i <= n ; i ++ ) f1[i] = f2[i] = 1e18;
		for(auto u : tmp[l])
			for(int i = 1 ; i <= n ; i ++ )
				f1[i] = min(f1[i], u.y + dist[u.x][i]);
		for(auto u : tmp[r])
			for(int i = 1 ; i <= n ; i ++ )
				f2[i] = min(f2[i], u.y + dist[u.x][i]);
		for(int i = 1 ; i <= n ; i ++ ) ans = min(ans, f1[i] + f2[i]);
		cout << ans + w[l] + w[r] << "\n";
	}
	return 0;
}
