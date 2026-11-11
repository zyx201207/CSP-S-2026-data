#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+9;
const int INF=1e9;
struct E
{
	int v;
	ll w;
};
struct Q
{
	int u;
	ll w;
	bool operator < (const Q& a) const
	{
		return w>a.w;
	}
};
priority_queue<Q> q;
vector<E> e[MAXN];
int n,m;
ll a[MAXN];
int dis[MAXN];
bool ft[MAXN];
void dij(int s)
{
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(ft[u]) continue;
		ft[u]=1;
		for(auto qwq:e[u])
		{
			int v=qwq.v;
			ll w=qwq.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back({v,1});
		e[v].push_back({u,1});
	}
	srand(time(0));
	int ans=1e9,cnt=0;
	for(int i=1;i<=60;i++)
	{
		int x=rand()%n+1,y=rand()%n+1;
		while(x==y)
		{
			x=rand()%n+1,y=rand()%n+1;
		}
		for(int i=1;i<=n;i++)
		{
			dis[i]=INF;
			ft[i]=0;
		}
		dij(x);
		for(int i=1;i<=n;i++)
		{
			ft[i]=0;
		}
		dij(y);
		
		for(int i=1;i<=n;i++)
		{
			cnt=max(cnt,dis[i]);
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)e[i].clear(); 
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    
    int c,T;
    cin>>c>>T;
    while(T--)
    {
    	solve();
	}
    
    return 0;
}
