#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
看的我有点怕怕的
首先考虑最暴力的做法
首先考虑建图
对于一个线路i
它和线路j之间的权值是min(ti u+tj v)（这个地方保证一下ai u=aj v）
这个东西是很好处理的，是有你喜欢的东西存储一下a数组
但是这个起点终点你需要枚举一下线路
感受一下就很慢。。。
假设起点x，终点y
最坏是qn^2的
然后你就发现，欸由于空间有限。。。。。。d<=20
就是qd^2的查询（！
然后就做完了
真是傻逼题
1h 200
但是好紧张
感觉下次需要镇定剂
时间限制1s，是不是可能被卡常
但是CCF的机子估计比本地块很多吧 

*/
const int N = 500 + 10;
const int S = 5e5 + 10;
const int D = 21;
const ll INF = 1e18;
int sub0[S];
int sub[D][S];
int sut[D][S];
ll dis[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<ll> ww(m + 1);
	for (int i = 1; i <= m; ++i)
	{
		cin >> ww[i];
	}
	vector<int> k(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j)
		{
			int xx, yy;
			cin >> xx >> yy;
			sub[++sub0[xx]][xx] = i;
			sut[sub0[xx]][xx] = yy;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dis[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= sub0[i]; ++j)
		{
			for (int k = j + 1; k <= sub0[i]; ++k)
			{
//				cout << sub[j][i] << " " << sub[k][i] << "\n";
				dis[sub[j][i]][sub[k][i]] = min(dis[sub[j][i]][sub[k][i]], 1ll * sut[j][i] + sut[k][i]);
				dis[sub[k][i]][sub[j][i]] = min(dis[sub[k][i]][sub[j][i]], 1ll * sut[j][i] + sut[k][i]);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i != k && j != k)
				{
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}
//	for (int i = 1; i <= d; ++i)
//	{
//		for (int j = 1; j <= m; ++j)
//		{
//			cout << sub[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1 ; j <= n; ++j)
//		{
//			if (dis[i][j] != INF) cout << dis[i][j] << " ";
//			else cout << "- "; 
//		}
//		cout << "\n";
//	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int lenx = sub0[x], leny = sub0[y];
//		cout << sub[1][x] << " ";
		ll ret = INF;
		for (int i = 1; i <= lenx; ++i)
		{
			for (int j = 1; j <= leny; ++j)
			{
				if (sub[i][x] != sub[j][y])
					ret = min(ret, dis[sub[i][x]][sub[j][y]] + sut[i][x] + sut[j][y]);
				else
					ret = min(ret, 1ll * sut[i][x] + sut[j][y]);
//					cout << sut[i][x] << " " << sut[j][y] << "\n";
//				if (sub[i][x] == sub[j][y]) ret = min(ret, 1ll * sut[i][x] + sut[i][y]);
			}
		}
		cout << ret + ww[x] + ww[y] << "\n";
	}
}
