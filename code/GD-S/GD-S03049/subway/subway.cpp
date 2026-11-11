#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
#define fi first
#define se second
const long long N=505,M=5e5+5;
const long long INF=1e18;
long long c,n,m,d,Q,k[N];
bool vis[M];
long long dis[N][N],w[M];
vector<pii>ps[N],hav[M];
vector<long long>e[N];
void init(long long st)
{
	for(long long i=1;i<=n;i++)vis[i]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,st});vis[st]=1;
	while(!q.empty())
	{
		long long d=q.top().fi;
		long long u=q.top().se;q.pop();
		if(d>dis[st][u])continue;
		for(long long v:e[u])
		{
			long long nd=dis[u][v]+d;
			if(nd>=dis[st][v]&&vis[v])continue;
			q.push({nd,v});dis[st][v]=nd;vis[v]=1;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)
		{
			long long id,wk;cin>>id>>wk;
			hav[id].push_back({i,wk});
			ps[i].push_back({id,wk});
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(long long i=1;i<=m;i++)
	{
		for(long long l=0;l<hav[i].size();l++)
		{
			long long u=hav[i][l].fi;
			long long w1=hav[i][l].se;
			for(long long r=l+1;r<hav[i].size();r++)
			{
				long long v=hav[i][r].fi;
				long long w2=hav[i][r].se;
				dis[u][v]=min(dis[u][v],w1+w2);
				dis[v][u]=min(dis[v][u],w1+w2);
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			if(dis[i][j]!=INF||i==j)
			{
				e[i].push_back(j);
			}
		}
	}
	for(long long i=1;i<=n;i++)init(i);
	while(Q--)
	{
		long long x,y;cin>>x>>y;
		long long ans=INF;
		for(pii i:hav[x])
		{
			for(pii j:hav[y])
			{
				ans=min(w[x]+w[y]+dis[i.fi][j.fi]+i.se+j.se,ans);
			}
		}
		cout<<ans<<"\n";
	}
}
