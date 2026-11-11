#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 5e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

/*
题意: 
现有一张 m 个点的图, 每个节点上有两个子节点, 这两个子节点由一条带权无向边连着, 令这两个节点为 (u,v) 
现有 n 条线路, 对于 1 <= i <= n 的第 i 条线路, 有以下规则
- v 贴着线路 
- 经过 ki 个节点
- 在线路上第 i 个节点处, 有一条边为 (v,i,t)
- 最多只有 d 条边经过这个节点
- 所有节点凭线路连通
现有 q 个计划, 对于 1 <= i <= n 的第 i 条计划, 有以下规则
- 起点 xi, 终点 yi 
- 途中可能有换乘, 令换乘为 (u, v1) 换到 (u, v2) 则需要先走到 u, 再走到 v2 
*/ 

// 如何实现线路? 在路径上建边 
// 站厅是什么? 可以看作一个地铁站的超级源点 
// 怎么存图? g[i*(d+1)]存站厅, g[i*(d+1)+1...+d]存站台, 其中 (1 <= i <= m) 表示地铁站 *因为 d 最大只有 20, 所以存的下 
// 地铁口怎么办? 只有起点和终点的地铁口对答案有影响, 单独拿数组存即可 
// 补充: 由于题目只要步行, 因此存站台到站厅即可 

struct Node{
	int v;
	ll w;
	bool operator < (const Node &o) const 
	{
		return (o.w > w);
	}
	bool operator > (const Node &o) const
	{
		return (w < o.w);
	}
};

int c,n,m,d,q; 
vector<Node> g[maxn*505];
ll w[maxn]; // 地铁口到站厅 
ll dis[maxn*505];

void Dij(int s)
{
	fill(dis+1,dis+1+n,INF);
	priority_queue<Node, vector<Node>, greater<Node> > q;
	dis[s] = 0;
	q.push({s,0});
	while(!q.empty())
	{
		int u = q.top().v;
		q.pop();
		for(auto &x : g[u])
		{
			int v = x.v, w = x.w;
			if(dis[v] > dis[u]+w)
			{
				dis[v] = dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	} 
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		vector<int> l;
		for(int j=1;j<=k;j++)
		{
			int id; cin>>id; l.push_back(id);
			int t; cin>>t;
			g[id*(d+1)].push_back({id*(d+1)+i,t});
		}	
	}
	
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		Dij(s*(d+1));
		ll ans = dis[t*(d+1)]+w[s]+w[t];
		cout<<ans<<'\n';
	}
	
	return 0;
} 
