//GZ-S00038 贵阳市白云区华师一学校 林乾翔 
//这个就是很直接
//建图之后跑最短路
//分析一下复杂度
//首先你建图对于每一个点都要建
//显然是sigma k的
//然后无疑是奇怪的
//也就是说对于每一个qi都要跑一遍最短路
//qmlogm的来了...
//这个只有32分
//但是我暂时没有更好的点子了
//斗愣个了 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
struct edge 
{
	int v,w;
};
struct node
{
	int num,dis;
};
bool operator >(node a,node b)
{
	return a.dis>b.dis;
}
int c,n,m,d,q,rp,w[N],k[N],dis[N]; 
bool vis[N];
vector<edge> g[N];
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<node,vector<node>,greater<node> > q;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.top().num;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u])
		{
			if(dis[e.v]>dis[u]+e.w)
			{
				dis[e.v]=dis[u]+e.w;
				q.push({e.v,dis[e.v]});
			}
		}
	}
}
void bfs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<node> q;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.front().num;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u])
		{
			if(dis[e.v]>dis[u]+e.w)
			{
				dis[e.v]=dis[u]+e.w;
				q.push({e.v,dis[e.v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	rp=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			rp++;
			if(j!=k[i]) 
			{
				g[rp].push_back({rp+1,0});
				g[rp+1].push_back({rp,0});
			}
			g[rp].push_back({a,t});
			g[a].push_back({rp,t});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(c>=12&&c<=19) bfs(x);
		else dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
//CSP-S 2026 rp++
//管理好时间
//记得打暴力
//今年能一等！！！
//相信自己。
//注意溢出和边界问题
//先把分拿完，然后手造样例过
//相信数据强度
//写对拍 
