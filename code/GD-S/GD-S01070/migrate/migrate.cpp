#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5,INF=1e9;
ll x[N];
bool vis[N];
set<pair<int,int>>ins;
int n,idx,h[N],dis[N],pre[N];
struct edge{int u,v,nxt;}e[2*N];
struct node{int id,dis;friend bool operator<(node a,node b){return a.dis>b.dis;}};
inline void add(int u,int v){e[++idx]={u,v,h[u]},h[u]=idx;}
void bfs(int st)
{
	priority_queue<node>s;
	for(int i=1;i<=n;i++)pre[i]=0,dis[i]=INF,vis[i]=false;
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
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				pre[v]=1,ins.insert({u,v});
				if(!vis[v])s.push({v,dis[v]});
			}
			else if(!ins.count({u,v}) and dis[v]==dis[u]+1)pre[v]+=pre[u],ins.insert({u,v});
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		int ans=0;ll d;
		scanf("%d%lld",&n,&d),idx=0;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]),h[i]=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				/*Òª¼Ó ll*/if(llabs(x[i]-x[j])<=d)
				{
					add(i,j),add(j,i);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			ins.clear();
			/*printf("CHECK:%d\n",i);
			for(int j=1;j<=n;j++)printf("%d ",pre[j]);
			printf("\n");*/
			for(int j=i+1;j<=n;j++)if(pre[j]==2)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
