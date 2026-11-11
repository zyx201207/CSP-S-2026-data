#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll,ll>
const int N=510;
const int M=5e5+5;
ll c,n,m,d,Q,w[M],k[N],dis[N];
bool vis[N];
vector<PII> e[N];
vector<PII> g[M];
struct st
{
	ll nxt,dis1;
};
vector<st> can[N];
queue<ll> q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			e[i].push_back(make_pair(x,y));
			g[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			ll u=g[i][j].first,disu=g[i][j].second;
			for(int ww=j+1;ww<g[i].size();ww++)
			{
				ll v=g[i][ww].first,disv=g[i][ww].second;
				can[u].push_back((st){v,disu+disv});
				can[v].push_back((st){u,disv+disu});
			}
		}
	}
	while(Q--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=n;i++) 
		{
			vis[i]=false;
			dis[i]=1e18;
		}
		for(int i=0;i<g[x].size();i++)
		{
			ll u=g[x][i].first;
			dis[u]=w[x]+g[x][i].second;
			vis[u]=true;
			q.push(u);
		}
		while(!q.empty())
		{
			ll u=q.front();
			q.pop();
			vis[u]=false;
			for(int i=0;i<can[u].size();i++)
			{
				ll nxt=can[u][i].nxt,distance=can[u][i].dis1;
				if(dis[nxt]>dis[u]+distance)
				{
					dis[nxt]=dis[u]+distance;
					if(!vis[nxt])
					{
						q.push(nxt);
						vis[nxt]=true;
					}
				}
			}
		}
		ll ans=1e18;
		for(int i=0;i<g[y].size();i++)
		{
			ll v=g[y][i].first;
			ans=min(ans,dis[v]+w[y]+g[y][i].second); 
		}
		printf("%lld\n",ans);
	}
	/*while(Q--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=n;i++) 
		{
			vis[i]=false;
			dis[i]=1e18;
		}
		for(int i=0;i<g[x].size();i++)
		{
			ll u=g[x][i].first;
			dis[u]=w[x]+g[x][i].second;
			vis[u]=true;
			q.push(u);
		}
		while(!q.empty())
		{
			ll u=q.front();
			q.pop();
			vis[u]=false;
			for(int i=0;i<e[u].size();i++)
			{
				ll v=e[u][i].first;
				ll distance=e[u][i].second;
				for(int j=0;j<g[v].size();j++)
				{
					ll nxt=g[v][j].first,zhi=g[v][j].second;//u->nxt
					if(dis[nxt]>dis[u]+distance+zhi)
					{
						//cout<<u<<" "<<v<<" "<<distance<<" "<<nxt<<" "<<zhi<<endl;
						dis[nxt]=dis[u]+distance+zhi;
						if(!vis[nxt])
						{
							q.push(nxt);
							vis[nxt]=true;
						}
					}
				}
			}
		}
		ll ans=1e18;
		for(int i=0;i<g[y].size();i++)
		{
			ll v=g[y][i].first;
			ans=min(ans,dis[v]+w[y]+g[y][i].second); 
		}
		printf("%lld\n",ans);
	}*/
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
