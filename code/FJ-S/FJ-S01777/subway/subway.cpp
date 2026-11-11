#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;const long long INF=1e18+1;
int c,n,m,d,q;int w[N];
bool ac[501][500001]={false};
int t[501][500001];int kt[N];
long long dis[520];
bool vis[520];
struct Edge{
	int to,vl;
};
vector<Edge> ed[520];
inline long long calc(int st,int des)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	dis[st]=0;
	pq.push(make_pair(0,st));
	while(pq.size())
	{
		pair<int,int> top=pq.top();
		pq.pop();
		int u=top.second;
		if(vis[u]==true)continue;
		vis[u]=true;
		if(u==des)
		{
			return dis[des];
			break;
		}
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i].to,w=ed[u][i].vl;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.push(make_pair(dis[v],v));
			}
		}
	}
	return dis[des];
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&kt[i]);
		for(int j=1;j<=kt[i];j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			ac[i][x]=true;
			t[i][x]=y;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int kd[21]={0},cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(ac[i][j]==true)
			{
				kd[++cnt]=i;
			}
		}
		if(cnt==1)continue;
		for(int k=1;k<=cnt;k++)
		for(int l=k+1;l<=cnt;l++)
		{
		Edge e;
		e.vl=t[kd[k]][j]+t[kd[l]][j];
		e.to=kd[l];
		ed[kd[k]].push_back(e);
		e.to=kd[k];
		ed[kd[l]].push_back(e);
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<ed[i].size();j++)
		printf("%d %d %d\n",i,ed[i][j].to,ed[i][j].vl);
	}*/
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=w[u]+w[v],minn=INF;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(ac[i][u]&&ac[j][v])
			minn=fmin(minn,calc(i,j)+t[i][u]+t[j][v]);
		}
		printf("%lld\n",ans+minn);
	}
	return 0;
} 
