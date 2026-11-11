#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxd=114514114514114514;//1e17
int c,n,m,d,q,w[500005],k[505],dis[505][505],vis[505],ed[505][505];
struct s{int id,ti;};
struct edg{int v,w;};
vector<s>sta[500005];
vector<edg>edge[505];
priority_queue<pair<int,int> >qdij;
int read()
{
	int f=1,sum=0;
	char c=getchar();
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())sum=sum*10+c-'0';
	return sum*f;
}
void dijstra(int x)
{
	for(int i=1;i<=n;i++)dis[x][i]=maxd,vis[i]=0;
	dis[x][x]=0;while((int)qdij.size())qdij.pop();qdij.push({0,x});
	while(qdij.size())
	{
		int u=qdij.top().second;qdij.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<(int)edge[u].size();i++)
		{
			int v=edge[u][i].v,w=edge[u][i].w;
			if(dis[x][u]+w<dis[x][v])
			{
				dis[x][v]=dis[x][u]+w;
				if(vis[v])continue;
				qdij.push({dis[x][v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int u=1;u<=n;u++)
		for(int v=1;v<=n;v++)ed[u][v]=maxd;
	for(int u=1;u<=n;u++)
	{
		k[u]=read();
		for(int x,y,i=1;i<=k[u];i++)
		{
			x=read(),y=read();
			for(int j=0;j<(int)sta[x].size();j++)
			{
				int v=sta[x][j].id,w=sta[x][j].ti;
				ed[u][v]=min(ed[u][v],w+y);
				ed[v][u]=min(ed[v][u],w+y);
			}
			sta[x].push_back({u,y});
		}
	}
	for(int u=1;u<=n;u++)
		for(int v=1;v<=n;v++)
			if(ed[u][v]!=maxd)
				edge[u].push_back({v,ed[u][v]});
	for(int i=1;i<=n;i++)dijstra(i);
	for(int x,y,t=1;t<=q;t++)
	{
		x=read();y=read();int ans=maxd;
		for(int i=0;i<(int)sta[x].size();i++)
			for(int j=0;j<(int)sta[y].size();j++)
			{
				int u=sta[x][i].id,v=sta[y][j].id;
				ans=min(ans,dis[u][v]+sta[x][i].ti+sta[y][j].ti+w[x]+w[y]);
				//cout<<t<<":"<<u<<' '<<v<<" "<<dis[u][v]<<" "<<dis[u][v]+sta[x][i].ti+sta[y][j].ti+w[u]+w[v]<<endl;
			}
		printf("%lld\n",ans);
	}
} //fc E:\GD-S02654\subway\subway.out E:\GD-S02654\subway\subway3.ans
