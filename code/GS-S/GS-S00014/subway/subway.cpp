#include <bits/stdc++.h>
using namespace std;

namespace ljw
{
	typedef long long ll;
	typedef pair<int, int> PII;
	
	const int N = 5e5 + 10, M = 510;
	int s[N];
	ll d[M][N], w[N];
	vector<PII> sub[N];
	vector<PII> g[N];

	struct Cow
	{
		int u;
		ll dist;
		
		inline bool operator< (const Cow &u) const
		{
			return dist > u.dist;
		}
	};

	void dijkstra(int k, int u)
	{
		priority_queue<Cow> heap;
		
		heap.push({u, sub[k][0].second});
		d[k][u] = sub[k][0].second;
		
		while (heap.size())
		{
			Cow t = heap.top();
			heap.pop();
			
			int u = t.u;
			ll dist = t.dist;
			
			if (dist > d[k][u]) break;
			
			for (auto i : g[u])
			{
				ll w = i.second;
				
				for (auto j : sub[i.first])
				{
					int ne = j.first;
					
					if (d[k][ne] > d[k][u] + j.second)
					{
						d[k][ne] = d[k][u] + j.second;
						heap.push({ne, d[k][ne]});
					}
				}
			}	
		}
	}
	
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		
		int c, n, m, D, q;
		cin >> c >> n >> m >> D >> q;
		
		for (int i = 1; i <= m; i++)
			cin >> w[i];
		
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			
			int v, w;
			for (int j = 0; j < s[i]; j++)
			{
				cin >> v >> w;
			
				sub[i].push_back({v, w});
				g[v].push_back({i, w});
			}
		}
		
		for (int i = 1; i <= n; i++)
			dijkstra(i, sub[i][0].first);
		
		int a, b;
		while (q--)
		{
			cin >> a >> b;
			
			ll res = w[a] + w[b], minx = 1e18;
			for (auto i : g[a])
			{
				int u = i.first;
				
				for (auto j : g[b])
				{
					int ub = j.first;
					
					for (auto p : sub[ub])
					{
						int k = p.first;
						
						minx = min(minx, d[u][k]);
					}						
				}
			}
			
			cout << res + minx << '\n';
		}
		
		
		return 0;
	}
}

int main()
{
	return ljw::main();
}
/*
我们观察题目有m个地铁站 
虽然只有最多500条路线但是计算总边数可以与m齐平
相当于给了一个正常的有向图（题目保证任意两点可以互通）
q很大<=1e5我们暴力dijkstra肯定不行 

我们再看从x站到y站  
每次乘坐地铁必须前往站厅选择 花费ti,j 
乘坐地铁线路 题目描述边权为点贡献
我们选择一种线路 不过同一条线路里面的点可以不按照给出顺序？
我们观察样例1 似乎按照顺序？交点只有2
观察样例2 依旧没有不按照顺序的证据 样例始终强调依次经过
那么就例如1线路1 2 4从2开始只能到4

我们还发现 除了最开始和最后要从站厅走到地铁口往返产生贡献
其他就不需要使用wi
 
总结
开始先从地铁口走到站厅 wi
然后中途更换线路 假设选择了k线路到了p 贡献t[k][Kid] 
那么下车后要从p走到站台t[k][Pid]
重复
最后到y了以后走回站厅wy

我们似乎陷入瓶颈了 暴力最多50% 
如果题目真的给我们一个1e5无向图还给q=1e5的查询我们没有机会做出来
但是如果真的是这样题目为什么要构造如此复杂的背景呢
我们观察到n<=500, d<=20 
最开始我们看了最多有500个线路
d<=20告诉我们每个点最多有20条边

我们能发现的是什么路线只有这么多
是按照顺序的
我们只有可能在这些路线中穿梭
考虑建边 也许这个图是特殊的 

我们把路线中的点全部串起来
每条路线的点存在两种决策
1.更换路线需要代价 t[i][j] 
2.无代价按照路线一直走下去 代价0 

500个线路是否意味我们最多跳500次更换500次就可以到达目的地呢

我们思考
x在很多线路里
y在很多线路里

一旦我们抵达y在线路中前面的任何一个点我们都可以结束了
我们一定是从x在线路中后面的任意节点出发的
我们想要到达所有线路开头的点
可是万一后面有一个点比他的花费更小呢
我们平均下来
假设q=1e5
我们在x的所有线路里
因为最多只有20条线路
如果我们在x所在的点跑dijkstra那么后面就是在线路上的点一定被考虑了的

最多20条线路
那么一个x有最多有20个点
不能这么算

那么既然在线路i上的x节点跑了一定会考虑线路i上后面的
我在所有线路开头跑dijkstra
可是我当前拥有的不代表后面拥有
如果我把线路上所有节点一起放入队列呢
那这个d[i]代表什么了代表当前线路上可以到达节点的最短路径可是和开头放一样啊 

可是一共有1e5个x我不可能所有都跑一边
问题是所有x在一条线路中肯定不可能是开头
 
还有1个小时了

还有救吗

我们把地铁站当作点
换乘当作边
我们x和y包含的地铁站不考虑
我是题读错了吗
在同一个线路可以经过，可题目说同一个线路不会经过同一个地铁站

x后面的点
y前面的点

可是变成其他点

我想要从他开始
何尝不是呢

我们想现实中的一条线路 是循环的吧
是重复经过的吧
他说地铁网络联通
我认为地铁是双向的吧

所以如果是这样那么

我把线路变成点

只要到达线路就算过关了

试一试吧也许是对的
我每次把所有线路开头的加入dijkstra跑500次

第几个线路到达哪个点都是可以的
最后看x的所有线路到y的所有线路的点是不是存在的
如果存在res = min{d[线路i][点j]}

我们发现样例2让两个5都很大 似乎在暗示我们这个线路中的任何一个点都是"双向"的 
 
 
*/
