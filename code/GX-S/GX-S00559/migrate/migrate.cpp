#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1e6+100;
long long t,n,d,ans;
int head[MAXN],idx=0,a[MAXN];
struct Edge
{
	int next,to;
	int w;
}edge[MAXN<<1];
void add(int u,int v,int w)
{
	edge[idx].next=head[u];
	edge[idx].to=v;
	edge[idx].w=w;
	head[u]=idx++;
}
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
long long dis[MAXN],cnt[MAXN];
bool visit[MAXN];
long long maga(long long num)
{
	if(num<0)
		return 0-num;
	else
		return num;
}
void dijkstra(int start)
{
	while(!pq.empty())
		pq.pop();
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(visit,false,sizeof(visit));
	dis[start]=0;
	cnt[start]=1;
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
			if(dis[v]==dis[u]+w)
				cnt[v]+=cnt[u];
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u];
				pq.push({dis[v],v});
			}
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld",&t);
	scanf("%lld",&t);
	for(int m=1;m<=t;m++)
	{
		memset(head,-1,sizeof(head));
		idx=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)
				{
					add(i,j,1); 
					add(j,i,1);
				}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			dijkstra(i);
			for(int j=1;j<=n;j++)
				if(cnt[j]==2)
					ans++;
		}
		printf("%lld\n",ans>>1);
	}
    return 0;
}
