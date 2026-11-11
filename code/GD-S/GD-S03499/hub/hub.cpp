#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,k;
int Tid;
vector<int>edge[N];
int h[N];
int fa[N];
inline void dfs(int x)
{
	h[x]=0;
	for(int v:edge[x])
	{
		if(v==fa[x])continue;
		fa[v]=x;
		dfs(v);
		h[x]=max(h[x],h[v]+1);
	}
}
bool vis[N];
int ans;
int dis[N];
inline void getp(int st,int vv,int x,int ff,int ds)
{
	if(ds/2>ans)return;
	if(vv!=-1)
	{
		fa[st]=vv;
		dfs(st);
		fa[x]=ff;
		dfs(x);
		int nk=k-2;
		for(int i=1;i<=n;i++)vis[i]=0;
		vis[st]=vis[x]=1;
		priority_queue<pair<int,int>>Q;
		for(int v:edge[st])
			if(v!=fa[st])
				Q.push({h[v],v});
		for(int v:edge[x])
			if(v!=fa[x])
				Q.push({h[v],v});
		while(nk--&&!Q.empty())
		{
			int u=Q.top().second;
			Q.pop();
			vis[u]=1;
			for(int v:edge[u])
			{
				if(v==fa[u])continue;
				Q.push({h[v],v});
			}
		}
		queue<int>q;
		for(int i=1;i<=n;i++)
			dis[i]=1e9;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				q.push(i);
				dis[i]=0;
			}
		}
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int v:edge[u])
			{
				if(dis[v]>dis[u]+1)
				{
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++)res=max(res,dis[i]);
		ans=min(ans,res); 
	}
	for(int v:edge[x])
	{
		if(v==ff)continue;
		getp(st,vv==-1?v:vv,v,x,ds+1);
	}
}
inline void solve()
{
	ans=1e9;
	cin>>n>>k;
	if(n<=2)
	{
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++)edge[i].clear();
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		getp(i,-1,i,0,0);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int T;cin>>Tid>>T;
	while(T--)solve();
}
