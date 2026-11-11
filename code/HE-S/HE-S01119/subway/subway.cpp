#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
const int N=550,M=5e5+10;
int c,n,m,d,qq;
vector<int> mp[N];
int val[N][N];
int ch[M][30];
int dis[N][N];
int val1[M];//µØÌú¿Úµ½Õ¾Ìü
P val2[M][30];
int len[M];
int vis[N];
priority_queue<P,vector<P>,greater<P> > q;
void dij(int s)
{
	dis[s][s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for (int i : mp[u])
		{
			int w=val[u][i];
			if(dis[s][i]>dis[s][u]+w)
			{
				dis[s][i]=dis[s][u]+w;
				q.push({dis[s][i],i});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	{
		cin>>val1[i];
	}
	for (int i=1;i<=n;i++)
	{
		int k,a,t;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>a>>t;
			val2[a][++len[a]]={t,i};
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=len[i];j++)
		{
			for (int k=j+1;k<=len[i];k++)
			{
				int u=val2[i][j].second,v=val2[i][k].second;
				if(!val[u][v])
				{
					mp[u].push_back(v);
					mp[v].push_back(u);
					val[u][v]=val2[i][j].first+val2[i][k].first;
					val[v][u]=val2[i][j].first+val2[i][k].first;
				}
				else
				{
					val[u][v]=min(val[u][v],val2[i][j].first+val2[i][k].first);
					val[v][u]=min(val[v][u],val2[i][j].first+val2[i][k].first);
				}
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(int)*(n+10));
		while(!q.empty())q.pop();
		dij(i);
	}
	while(qq--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for (int i=1;i<=len[x];i++)
		{
			for (int j=1;j<=len[y];j++)
			{
				int u=val2[x][i].second,v=val2[y][j].second;
				ans=min(ans,dis[u][v]+val1[x]+val1[y]+val2[x][i].first+val2[y][j].first);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
