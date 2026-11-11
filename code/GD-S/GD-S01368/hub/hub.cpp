#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=1010; 
bool is[N],vis[N];
ll T,c,n,k,u,v,ans=1e18;
ll dis[N];
vector<ll> e[N];

ll dij(ll s)
{
	ll minn=1e18;
	for(ll i=1;i<=n;i++) dis[i]=1e18;
	
	queue<ll> q;
	q.push(s);dis[s]=0;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		
		for(auto v:e[u])
		{
			if(dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	
	for(ll i=1;i<=n;i++) if(is[i]) minn=min(minn,dis[i]);
	return minn;
}

void dfs(ll cnt,ll i,vector<ll> s)
{
	if(i>n)
	{
		if(cnt!=k) return;
		//是否处于同一个或两个连通块当中 
		ll num=0;
		memset(vis,0,sizeof(vis));
		for(ll i=0;i<s.size();i++)
		{
			if(!vis[s[i]])
			{
				num++;
				queue<ll> q;
				q.push(s[i]);
				while(!q.empty())
				{
					ll u=q.front();
					q.pop();
					
					if(vis[u]) continue;
					vis[u]=1;
					
					for(auto v:e[u]) q.push(v);
				}
			}
		}
		if(num>2) return;
		
		memset(is,0,sizeof(is));
		for(ll i=0;i<s.size();i++) is[s[i]]=1;
		
		ll maxn=0;
		for(ll i=1;i<=n;i++) if(!is[i]) maxn=max(dij(i),maxn);
		ans=min(ans,maxn);
		return;
	}
	
	dfs(cnt,i+1,s);
	s.push_back(i);
	dfs(cnt+1,i+1,s);
	return;
}

void solve()
{
	for(ll i=1;i<N;i++) e[i].clear();
	cin>>n>>k;
	for(ll i=1;i<n;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	vector<ll> s;
	dfs(0,1,s);
	cout<<ans<<endl;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
