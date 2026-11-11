#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back

inline int read()
{
	int x;
	cin>>x;
	return x;
}

int n,m,d,q,mn[510],k[510],vis[510],w[500010];
int dis[510][510];
vector<int>a[510],t[510];
vector<int>pos[500010];
vector<pii>e[510];
unordered_map<int,int>tim[510];

inline void dij(int st)
{
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=n;i++)
		dis[st][i]=1e18,vis[i]=0;
	q.push({0,st});dis[st][st]=0;
	while(!q.empty())
	{
		int x=q.top().se;q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(pii i:e[x])
		{
			int y=i.fi,w=i.se;
			if(dis[st][y]>dis[st][x]+w)
			{
				dis[st][y]=dis[st][x]+w;
				q.push({dis[st][y],y});
			}
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=0;j<k[i];j++)
		{
			int x=read(),y=read();
			a[i].pb(x);
			t[i].pb(y);
			pos[x].pb(i);tim[i][x]=y;
		}
	}
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=n;i++)
			mn[i]=1e18;
		for(int i=0;i<k[x];i++)
			for(int j:pos[a[x][i]])
				mn[j]=min(mn[j],tim[j][a[x][i]]+t[x][i]);
		for(int i=1;i<=n;i++)
			if(mn[i]!=1e18&&i!=x)
				e[x].pb({i,mn[i]});
	}
	for(int i=1;i<=n;i++)
		dij(i);
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read(),ans=1e18;
		for(int st:pos[x])
			for(int ed:pos[y])
				ans=min(ans,w[x]+w[y]+dis[st][ed]+tim[st][x]+tim[ed][y]);
		cout<<ans<<'\n';
	}
	return 0;
}

