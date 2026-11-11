#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1e7+100;
long long n,m,q;
long long a[MAXN];
int head[MAXN],cnt=0;
struct Edge
{
	int next,to;
	int w;
}edge[MAXN<<1];
void add(int u,int v,int w)
{
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=w;
	head[u]=cnt++;
}
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
long long dis[MAXN];
bool visit[MAXN];
void dijkstra(int start)
{
	while(!pq.empty())
		pq.pop();
	memset(dis,0x3f,sizeof(dis));
	memset(visit,false,sizeof(visit));
	dis[start]=0;
	pq.push({0,start});
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(visit[u])
			continue;
		visit[u]=true;
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			long long w=edge[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld%lld%lld",&n,&m,&q);
	scanf("%lld",&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int k=0,id[MAXN],d[MAXN];
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d%d",&id[j],&d[j]);
		for(int j=1;j<k;j++)
			for(int l=j+1;l<=k;l++)
			{
				add(id[l],id[j],d[l]+d[j]);
				add(id[j],id[l],d[l]+d[j]);
			}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dijkstra(x);
		printf("%lld\n",dis[y]+a[x]+a[y]);
	} 
    return 0;
}
/*
 
	for(int i=1;i<=m;i++)
	{
		printf("%d     ",i);
		for(int j=head[i];j!=-1;j=edge[j].next)
			printf("%d %d   ",edge[j].to,edge[j].w);
		printf("\n");
	}
 */
