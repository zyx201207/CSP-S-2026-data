#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int n;ll d;
ll x[N];
ll g[N][N];
int vis[N];
ll dis[N][N];
void bfs(int s)
{
	queue<int>q;
	q.push(s);
	for(int i=1;i<=n;++i)vis[i]=0,dis[s][i]=1e9;
	dis[s][s]=0;vis[s]=1;g[s][s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=u+1;i<=n;++i)
		{
			if(x[i]-x[u]<=d)
			{
				if(dis[s][i]>dis[s][u]+1)
				{
					dis[s][i]=dis[s][u]+1;
					g[s][i]=g[s][u];
					if(!vis[i])vis[i]=1,q.push(i);
				}
				else if(dis[s][i]==dis[s][u]+1)
				{
					g[s][i]+=g[s][u];
				}
			}
		}
	}
}
inline void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			g[i][j]=0;
		}
	}
	for(int i=1;i<=n;++i)
	{
		bfs(i);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(g[i][j]==2)++ans;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0),cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--)solve();
}
