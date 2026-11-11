#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5,M=505,INF=1e18;
vector<pair<int,int>>Q[N];
struct edge{int u,v,w,nxt;}e[2*N];
int c,n,m,d,q,idx,w[N],h[N];ll dis[N],G[M][M];bool vis[N];
inline void add(int u,int v,int w){e[++idx]={u,v,w,h[u]},h[u]=idx;}
struct node{int id;ll dis;friend bool operator<(node a,node b){return a.dis>b.dis;}};
void dijkstra(int st)
{
	priority_queue<node>s;
	for(int i=1;i<=n+m;i++)dis[i]=INF,vis[i]=false;
	s.push({st,0}),dis[st]=0;
	while(!s.empty())
	{
		int u=s.top().id;
		s.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=h[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(!vis[v])s.push({v,dis[v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(h,-1,sizeof(h));
	//为每个线路建一个虚拟节点 [线 i] 对应节点 i+m 
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int j=1;j<=n;j++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int a,t;
			cin>>a>>t;
			//add(j+m,a,t),add(a,j+m,t);
			Q[a].push_back({j,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if(i==j)G[i][j]=0;
		else G[i][j]=INF;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)Q[i].size();j++)
		{
			for(int k=j+1;k<(int)Q[i].size();k++)
			{
				int L=Q[i][j].first,R=Q[i][k].first;
				ll A=Q[i][j].second,B=Q[i][k].second;
				G[L][R]=min(G[L][R],A+B),G[R][L]=min(G[R][L],A+B);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if(G[i][j]==INF)continue;
		add(i,j,G[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
		for(int j=1;j<=n;j++)G[i][j]=dis[j];
	}
	while(q--)
	{
		int x,y;ll ans=INF;
		cin>>x>>y;
		for(auto i:Q[x])for(auto j:Q[y])
		{
			int L=i.first,R=j.first;
			int A=i.second,B=j.second;
			ans=min(ans,G[L][R]+A+B+w[x]+w[y]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
