#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'
#define Pair pair <int,int>
#define min(x,y) (x < y ? x : y)

const int N = 5e5 + 10,M = 5e2 + 10,INF = 1e17;
int cid,n,m,d,q,w[N],f[M][M];
vector <Pair> v[N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> cid >> n >> m >> d >> q;
//	cout << "q:" << q << endl;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++)
	{
		int k;
		cin >> k;
		while (k --)
		{
			int a,t;
			cin >> a >> t;
			v[a].push_back(make_pair(i,t));
		 } 
	}
	for(int i = 0;i < M;i ++)
		for(int j = 0;j < M;j ++)
			f[i][j] = INF;
	for(int i = 0;i < M;i ++) f[i][i] = 0;
	for(int i = 1;i <= m;i ++)
		for(int j = 0;j < v[i].size();j ++)
			for(int k = j + 1;k < v[i].size();k ++) 
			{
				int x = v[i][j].first,y = v[i][k].first;
				int xp = min(f[x][y],v[i][j].second + v[i][k].second);
				f[x][y] = f[y][x] = xp;
			 } 
	for(int k = 1;k <= n;k ++)	
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
//	cout << q << endl;
	while (q --)
	{
		int x,y;
		cin >> x >> y;
		int res = INF;
		for(int i = 0;i < v[x].size();i ++)
			for(int j = 0;j < v[y].size();j ++)
			{
				int r1 = v[x][i].first,r2 = v[y][j].first;
				res = min(res,f[r1][r2] + v[x][i].second + v[y][j].second);	
			}
		cout << res + w[x] + w[y] << endl;
	}
//	cout << "finished!" << endl;
	return 0;
 } 
 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
 
 
 

