#include <bits/stdc++.h>
#define rep1(i,a,b) for (int i = a;i <= b;i++)
#define int long long
#define fix(x,y) ((x) = min((x),(y)))
using namespace std;
/*
n<=500 m<=5e5 d<=20 q<=1e5
地铁口 -> 站厅 -> 站台，注意地铁上的时间忽略不计！ 
w[v]就是用来干扰的，开始和结束的站各加一次即可
每条地铁线路独立考虑，同线路上的u->v代价为：u站厅->站台  +  v站厅->站台 
每次旅行中，一定不会访问同一条线路两次
n<=500，可以Floyd求每两条线路之间的换乘代价！然后对于每次询问，直接枚举起点和终点分别搭哪条就行了！
怎么求每两条线路之间的换乘代价？
对着每个换乘点枚举！
15:32 AC
*/
const int N = 5e5 + 10;
const int M = 510;
const int INF = 0x3f3f3f3f3f3f3f3fll;
int n,m,d,q,u,v;
int w[N],k[M],f[M][M];
//每个点有哪些线路通过：<线路编号，站厅到站台时间>
vector<pair<int,int>> line[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> n >> n >> m >> d >> q;
	rep1(i,1,m)
		cin >> w[i];
	rep1(i,1,n)
	{
		cin >> k[i];
		rep1(j,1,k[i])
		{
			cin >> u >> v;
			line[u].push_back({i,v});
		}
	}
	//Floyd
	rep1(i,1,n)
		rep1(j,1,n)
			if (i != j)
				f[i][j] = INF;
	rep1(i,1,m)
		if (line[i].size() >= 2)
			rep1(j,0,line[i].size() - 2)
				rep1(k,j + 1,line[i].size() - 1)
				{
					fix(f[line[i][j].first][line[i][k].first],line[i][j].second + line[i][k].second);
					fix(f[line[i][k].first][line[i][j].first],line[i][k].second + line[i][j].second);
				}
	rep1(k,1,n)
		rep1(i,1,n)
			rep1(j,1,n)
				fix(f[i][j],f[i][k] + f[k][j]);
	//query
	while (q--)
	{
		cin >> u >> v;
		int ans = INF;
		for (auto x : line[u])
			for (auto y : line[v])
				fix(ans,x.second + y.second + f[x.first][y.first]);
		cout << ans + w[u] + w[v] << '\n';
	}
}

