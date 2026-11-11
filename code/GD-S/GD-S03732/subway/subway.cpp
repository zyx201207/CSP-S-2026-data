#include<bits/stdc++.h> 
using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::priority_queue;
using std::min;
using std::greater;
namespace my{
	struct Edge{
		int v,w;
	};
	struct NodeQ{
		long long w;
		int u;
		bool operator > (const NodeQ &n) const{
			return w > n.w;
		}
	};
	struct Pair{
		int a,t;
	};
	int n,m,d,q,w[1005],a[305],t[305],edge[305][305],cedge[505][505];
	long long dis[1005][1005],dis2[505][505];
	bool mark[1005],mark2[505];
	vector<Edge> e[1005],ec[505];
	vector<Pair> cross[500005];
	inline void dijkstra(int s){
		priority_queue<NodeQ,vector<NodeQ>,greater<NodeQ> > que;
		memset(mark,0,sizeof(mark));
		memset(dis[s],0x3f,sizeof(dis[s]));
		dis[s][s] = 0;
		que.push(NodeQ{0,s});
		while(!que.empty())
		{
			int u = que.top().u;
			que.pop();
			if(mark[u])
			{
				continue;
			}
			mark[u] = true;
			int vsiz = e[u].size();
			for(int i = 0;i < vsiz;i += 1)
			{
				int v = e[u][i].v,w = e[u][i].w;
				if(dis[s][v] > dis[s][u] + w)
				{
					dis[s][v] = dis[s][u] + w;
					que.push(NodeQ{dis[s][v],v});
				}
			}
		}
		return;
	}
	inline void dijkstra2(int s){
		priority_queue<NodeQ,vector<NodeQ>,greater<NodeQ> > que;
		memset(mark2,0,sizeof(mark2));
		memset(dis2[s],0x3f,sizeof(dis2[s]));
		dis2[s][s] = 0;
		que.push(NodeQ{0,s});
		while(!que.empty())
		{
			int u = que.top().u;
			que.pop();
			if(mark2[u])
			{
				continue;
			}
			mark2[u] = true;
			int vsiz = ec[u].size();
			for(int i = 0;i < vsiz;i += 1)
			{
				int v = ec[u][i].v,w = ec[u][i].w;
				if(dis2[s][v] > dis2[s][u] + w)
				{
					dis2[s][v] = dis2[s][u] + w;
					que.push(NodeQ{dis2[s][v],v});
				}
			}
		}
		return;
	}
}using namespace my;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	int _;
	cin>>_>>n>>m>>d>>q;
	for(int i = 1;i <= m;i += 1)
	{
		cin>>w[i];
	}
	if(7 <= _ && _ <= 11)			//特殊性质 A 
	{
		for(int i = 1;i <= n;i += 1)		//能否绕一圈回来？研究样例发现可以，否则不连通 
		{
			int k;
			cin>>k;
			for(int j = 1;j <= k;j += 1)
			{
				cin>>a[j]>>t[j];
			}
			for(int j = 1;j <= k - 1;j += 1)
			{
				e[a[j]].emplace_back(Edge{a[j + 1],t[j] + t[j + 1]});
			}
			e[a[k]].emplace_back(Edge{a[1],t[k] + t[1]});	//最后一条边 
		}
		for(int i = 1;i <= m;i += 1)		//直接处理出全图最短路矩阵 
		{
			dijkstra(i);
		}
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			cout<<dis[u][v] + w[u] + w[v]<<'\n';
		}
	}
	else if(_ <= 6)		//暴力做法 
	{
		memset(edge,0x7f,sizeof(edge));
		for(int i = 1;i <= n;i += 1)
		{
			int k;
			cin>>k;
			for(int j = 1;j <= k;j += 1)
			{
				cin>>a[j]>>t[j];
			}
			for(int u = 1;u < k;u += 1)		//控制最终图的边数 
			{
				for(int v = u + 1;v <= k;v += 1)
				{
					edge[a[u]][a[v]] = min(edge[a[u]][a[v]],t[u] + t[v]);
					edge[a[v]][a[u]] = edge[a[u]][a[v]];
				}
			}
		}
		for(int i = 1;i < m;i += 1)
		{
			for(int j = i + 1;j <= m;j += 1)
			{
				int t = edge[i][j];
				if(t != 0xf7f7f7f)
				{
					e[i].emplace_back(Edge{j,t});
					e[j].emplace_back(Edge{i,t});
				}
			}
		}
		for(int i = 1;i <= m;i += 1)		//直接处理出全图最短路矩阵 
		{
			dijkstra(i);
		}
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			cout<<dis[u][v] + w[u] + w[v]<<'\n';
		}
	}
	else		//我要开始写正解了，呜呜呜我正解没写出来喵 
	{
		for(int i = 1;i <= n;i += 1)
		{
			int k;
			cin>>k;
			for(int j = 1;j <= k;j += 1)
			{
				int x,y;
				cin>>x>>y;
				cross[x].emplace_back(Pair{i,y});		//x车站去i环代价为y
			}
		}
		memset(cedge,0x7f,sizeof(cedge));
		for(int i = 1;i <= m;i += 1)	//对于每一个车站，构造环与环相连的最短边 
		{
			int vsiz = cross[i].size();
			for(int x = 0;x < vsiz - 1;x += 1)	//路过i车站的第x,y个环之间的路径 
			{
				int rx = cross[i][x].a,xcost = cross[i][x].t;
				for(int y = x + 1;y < vsiz;y += 1)
				{
					int ry = cross[i][y].a,ycost = cross[i][y].t;
					cedge[rx][ry] = min(cedge[rx][ry],xcost + ycost);
					cedge[ry][rx] = cedge[rx][ry];
				}
			}
		}
		for(int i = 1;i <= n;i += 1)		//构造环之间的图
		{
			ec[i].emplace_back(Edge{i,0}); 		//可能在同一个环上下车 
			for(int j = i + 1;j <= n;j += 1)
			{
				int t = cedge[i][j];
				if(t != 0x7f7f7f7f)
				{
					ec[i].emplace_back(Edge{j,t});
					ec[j].emplace_back(Edge{i,t});
				}
			}
		}
		for(int i = 1;i <= n;i += 1)		//在环之间跑全源最短路 
		{
			dijkstra2(i); 
		}
		while(q--)
		{
			int u,v;
			long long ans = 0x3f3f3f3f3f3f3f3f;
			cin>>u>>v;
			int usiz = cross[u].size(),vsiz = cross[v].size();
			for(int i = 0;i < usiz;i += 1)	//枚举u去第i环，从第j环到v的代价 
			{
				int cu = cross[u][i].a,ucost = cross[u][i].t;
				for(int j = 0;j < vsiz;j += 1)
				{
					int cv = cross[v][j].a,vcost = cross[v][j].t;
					ans = min(ans,dis2[cu][cv] + ucost + vcost + w[u] + w[v]);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
