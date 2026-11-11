#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q,w[500010],k[505],x,y,f[1005][1005],ct,bj[1005],dis[1005],first[1000010],inf=0x3f3f3f3f3f3f3f3f;
int g1[500010],g2[500010];
bool g[505][505];
vector<int>a[505];
vector<int>t[505];
vector<int>c[500010];
typedef pair<int,int> pii;
struct node
{
	int to,next,w;
}tr[2000010];
void add(int x,int y,int z)
{
	tr[++ct].to=y;
	tr[ct].next=first[x];
	tr[ct].w=z;
	first[x]=ct;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		a[i].push_back(0),t[i].push_back(0);
		for(int j=1;j<=k[i];j++)cin>>x>>y,a[i].push_back(x),t[i].push_back(y); 
	}
	if(C==20||C==21)
	{
		for(int j=1;j<=k[1];j++)g1[a[1][j]]=t[1][j];
		for(int j=1;j<=k[2];j++)g2[a[2][j]]=t[2][j];
		int jd=inf;
		for(int i=1;i<=m;i++)if(g1[i]&&g2[i])jd=min(jd,g1[i]+g2[i]);
		while(q--)
		{
			cin>>x>>y;
			int ans=inf;
			if(g1[x]&&g1[y])ans=min(ans,w[x]+w[y]+g1[x]+g1[y]);
			if(g2[x]&&g2[y])ans=min(ans,w[x]+w[y]+g2[x]+g2[y]);
			if(g1[x]&&g2[y])ans=min(ans,w[x]+w[y]+g1[x]+g2[y]+jd);
			if(g2[x]&&g1[y])ans=min(ans,w[x]+w[y]+g2[x]+g1[y]+jd);
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(C>=12&&C<=19)
	{
		int qb=t[1][1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)c[a[i][j]].push_back(i);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<c[i].size();j++)
			{
				for(int p=j+1;p<c[i].size();p++)g[c[i][j]][c[i][p]]=g[c[i][p]][c[i][j]]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)if(g[i][j])add(i,j,1);
		}
		while(q--)
		{
			cin>>x>>y;
			int mi=inf;
			for(int i=0;i<c[x].size();i++)
			{
				int s=c[x][i];
				for(int j=1;j<=n;j++)bj[j]=0,dis[j]=inf;
				dis[s]=0;
				priority_queue<pii,vector<pii>,greater<pii> > q;
				q.push({0,s});
				while(q.size())
				{
					pii now=q.top();
					q.pop();
					int u=now.second;
					if(bj[u])continue;
					bj[u]=1;
					for(int p=first[u];p;p=tr[p].next)
					{
						int v=tr[p].to;
						if(dis[u]+tr[p].w<dis[v])
						{
							dis[v]=dis[u]+tr[p].w;
							q.push({dis[v],v});
						}
					}
				} 
				for(int j=0;j<c[y].size();j++)mi=min(mi,dis[c[y][j]]);
			}
			cout<<w[x]+w[y]+2*mi*qb+2<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int p=j+1;p<=k[i];p++)f[a[i][j]][a[i][p]]=f[a[i][p]][a[i][j]]=min(f[a[i][j]][a[i][p]],t[i][j]+t[i][p]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)if(f[i][j]!=inf)add(i,j,f[i][j]);
	}
	while(q--)
	{
		memset(bj,0,sizeof(bj));
		memset(dis,0x3f,sizeof(dis));
		cin>>x>>y;
		priority_queue<pii,vector<pii>,greater<pii> > q;
		q.push({0,x});
		dis[x]=0;
		while(q.size())
		{
			pii now=q.top();
			q.pop();
			int u=now.second;
			if(bj[u])continue;
			bj[u]=1;
			for(int i=first[u];i;i=tr[i].next)
			{
				int v=tr[i].to;
				if(dis[u]+tr[i].w<dis[v])
				{
					dis[v]=dis[u]+tr[i].w;
					q.push({dis[v],v});
				}
			}
		}
		cout<<w[x]+w[y]+dis[y]<<'\n';
	}
	return 0;
}
/*
20 2 10 20 7
4 2 7 1 8 6 5 1 2 8
6 1 2 2 3 3 7 4 3 6 2 8 1
6 2 4 4 6 5 7 6 9 7 2 9 4
1 3
2 4
2 5
3 9
1 9
4 8
*/
