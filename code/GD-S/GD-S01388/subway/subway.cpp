#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510;
const int M = 5e5 + 10;
const int D = 21; 
int c, n, m, d, q;
ll w[M];
struct Node
{
	ll tot, val;
};
vector<Node> vc[M];//对于每个地铁站经过其的路线及站厅到路线的距离 
ll k[N];//每条线路经过的站点数 
ll ans[N][N];//两地铁线路最短距离 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	ll x, y;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
//		cout << k[i] << '\n';
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> x >> y;//地铁站和进入站厅距离 
			vc[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) ans[i][j] = 0;//自己到自己的距离为0 
			else ans[i][j] = 1e18;//否则为极大值 
		}
	}
	for (int i = 1; i <= m; i++)//此处为复杂度瓶颈 
	{
		for (auto& p:vc[i])
		{
			for (auto& p1:vc[i])
			{
				if (p.tot == p1.tot) continue;//若为自身，则跳过 
				ans[p.tot][p1.tot] = ans[p1.tot][p.tot] = min(ans[p.tot][p1.tot], p.val + p1.val);//取两线路之间的min值 
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				ans[i][j] = ans[j][i] = min(ans[i][j], ans[i][k] + ans[k][j]);//floyd~
			}
		}
	}
	ll sum;
	bool pd;
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;//回收利用
		sum = 1e18;
		pd = false;
		for (auto& p:vc[x])
		{
			for (auto& p1:vc[y])
			{
				if (p.tot == p1.tot)
				{
					sum = w[x] + p.val + p1.val + w[y];//若在同一条线路上直接走，不可能有更小的答案 
					pd = true; 
					break; 
				}
				sum = min(sum, w[x] + p.val + p1.val + w[y] + ans[p.tot][p1.tot]);//答案为从x进入p的时间 + p->p1的时间 + 从y离开的时间 
			}
			if (pd) break;//直接跳出去 
		}
		cout << sum << '\n';
	}
	return 0;
}
/*
地铁线路极少，考虑记录线路之间到达的最短路
一个地铁站最多被20条线路经过，即考虑两个地铁站之间的最短路仅需400次min即可
建图方面，若对于每个地铁站均直接建边必定MLE，考虑等价地记录两个直接连接的地铁线路间的最小值，最多5e5*400次比对，TLE
注意到在考虑特殊性质B后和20,21测试点后，有且仅有两个点可能TLE
注意到可行性极高 
注意到我们需要省着点用内存，ll尽量少些，但计算所用必须ll防止奇怪的WA 
注意到还需要记录每条线路仅出站最短距离(进入站厅距离+出站距离)用于询问，啊不其实不用的，询问时考虑两地铁站间距离，进出站时间固定 
注意到大样例#6是完完全全的弱数据，还是得自己考虑特殊性质B和20,21 
不对，大样例#7不应该TLE 
哦对的对的，大样例#7AC了 
我们注意到测试点20,21 n<=2，这等价于d<=2，也就是说不用考虑了
特殊性质B似乎难以针对，疑似导向正解 
不对，所有线路总共经过站点数不大于5e5，则大样例#6已经是最强数据了(ki=1000)，则时间复杂度计算有误，若每个站点均达到最大通线路数，n=20时至多有2.5e4个有效站点，最多2.5e4*400次比对，易证此时比对次数取得上限，时间复杂度勉强达标(1e8) 
则期望得分100pts 
*/
