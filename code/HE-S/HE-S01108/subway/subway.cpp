#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
using namespace std;
#define int long long

const int N = 505, M = 5e5 + 10; // 地铁线个数，边/地铁站 的个数 
int c, n, m, d, q; 
int w[M]; 
int dis[N][N], p[N][N][2]; // 记录一下哪两个点走 
unordered_map<int, int> G[N]; // 每个点对应的权值，离散化一下 
vector<int> sub[M];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i]; 
	for(int i = 1; i <= n; i++) 
	{
		int k, x, t; cin >> k;
		for(int j = 1; j <= k; j++)	
			cin >> x >> t, G[i][x] = t,
			sub[x].push_back(i);
	}
	
	for(int i = 1; i <= m; i++)
		if(sub[i].size() > 1) 
			for(int x : sub[i])
				for(int y : sub[i])
					if(x != y && dis[x][y] > G[x][i] + G[y][i]) 
						dis[x][y] = dis[y][x] = G[x][i] + G[y][i],
						p[x][y][0] = p[y][x][0] = 
						p[x][y][1] = p[y][x][1] = i;
	
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j],
					p[i][j][0] = p[i][k][0],
					p[i][j][1] = p[k][j][1];
				
	for(int i = 1; i <= q; i++)
	{
		int x, y, res = 0x3f3f3f3f3f3f3f3f; 
		cin >> x >> y;
		for(auto a : sub[x])
			for(auto b : sub[y])
			{
				if(a == b) res = min(res, G[a][x] + G[a][y]);
				else 
				{
					int len1 = (p[a][b][0] == x) ? 0 : G[a][x];
					int len2 = (p[a][b][1] == y) ? 0 : G[b][y];
					res = min(res, len1 + dis[a][b] + len2);
				}
			}
		cout << res + w[x] + w[y] << '\n';	
	}
}

/*
对于每一个连接两条线路及以上的点做松弛
先在每一个线路内两两点连接算距离
之后对于每一个连接两条线路的点，考虑两线路中的点的权值和+中转费用
最后加上进地铁口距离 

记录两地铁线之间如果可以换乘，最小的代价是什么，从哪个点换过来的
计算开头和结尾的代价，应该是在一个地铁线上距离转换点的距离
之后，每两个可以相互转移的地铁线连边，权值为同一个点的换站费用
floyd跑任意两个地铁站之间的费用

遍历首尾所在的所有地铁线中，到转换点的距离，记作 len1, len2
然后再加上两点考虑的地铁线之间的距离 dis[i][j] 
*/
