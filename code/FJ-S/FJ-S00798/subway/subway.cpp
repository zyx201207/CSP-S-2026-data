#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
const int N = 5e5 + 10, M = 510;
vector<PIL> hh[N]; // 每个点被什么线路连接 
int c, n, m, d, q;
LL w[N]; 
LL mdis[M][M]; 

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int a; LL t;
			cin >> a >> t;
			hh[a].push_back({i, t});
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			mdis[i][j] = 1e18;
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		for(auto x : hh[i])
		{
			int u = x.first; LL w1 = x.second;
			for(auto y : hh[i])
			{
				int v = y.first; LL w2 = y.second;
				if(u == v) continue;
				LL W = w1 + w2; 
				mdis[u][v] = min(mdis[u][v], W);
				mdis[v][u] = min(mdis[v][u], W);
				//cout << u << ' ' << v << ' ' << W << '\n';
			}
			
		}
	}
	//cout << endl;
	//cout << "AAA" << '\n';
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{	
			for(int j = 1; j <= n; j++)
			{	
				mdis[i][j] = min(mdis[i][j], mdis[i][k] + mdis[k][j]); 
			}
		}
	}
	// cout << "BBB" <<'\n';
	 
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		LL ans = 1e18;
		for(auto xx : hh[x]) // 线路 + 站台距离 
		{
			for(auto yy : hh[y])
			{
				int xxx = xx.first, yyy = yy.first; // 线路 
				//cout << xxx << ' ' << yyy << '\n';
				if(xxx > yyy) swap(xxx, yyy);
				LL res = w[x] + xx.second + mdis[xxx][yyy] + yy.second + w[y]; 
				ans = min(ans, res);
			}
		}
		
		cout << ans << '\n';
	}
//	cout << "AAA" << '\n';
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
