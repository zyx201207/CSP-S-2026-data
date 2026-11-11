#include<bits/stdc++.h>
using namespace std;
namespace did
{
	#define int long long
	int c,n,m,d,q,w[500005],f[505][505];
	vector<pair<int,int> > g[1000],gg[500005];
	struct node{int x;int t;};
	bool operator<(node x,node y)
	{
		return x.t>y.t;
	}
	bool operator>(node x,node y)
	{
		return x.t<y.t;
	}
	int S2(int x,int y)
	{
		if(f[x][y]) return f[x][y];
		int dis[1000]={};
		bool vis[500005]={};
		for(int i=1;i<=n;i++) dis[i]=1e18;
		dis[x]=0;
		queue<node> q;q.push({x,0});
		while(!q.empty())
		{
			node u=q.front();q.pop();
			if(u.x==y) return f[x][y]=u.t;
			if(dis[u.x]!=u.t) continue;
			for(auto kk:g[u.x])
			{
				if(vis[kk.first])continue;
				vis[kk.first]=1;
				for(auto kkk:gg[kk.first])
				{
					int x=kk.second+kkk.second+u.t;
					if(dis[kkk.first]&&dis[kkk.first]<x)continue;
					q.push({kkk.first,x});
					dis[kkk.first]=min(dis[kkk.first],x);
				}
			}
		}
		return 0;
	}
	int S(int x,int y)
	{
		if(c>=12&&c<=19) S2(x,y);
		if(f[x][y]) return f[x][y];
		int dis[1000]={};
		bool vis[500005]={};
		for(int i=1;i<=n;i++) dis[i]=1e18;
		dis[x]=0;
		priority_queue<node> q;q.push({x,0});
		while(!q.empty())
		{
			node u=q.top();q.pop();
			if(u.x==y) return f[x][y]=u.t;
			if(dis[u.x]!=u.t) continue;
			for(auto kk:g[u.x])
			{
				if(vis[kk.first])continue;
				vis[kk.first]=1;
				for(auto kkk:gg[kk.first])
				{
					int x=kk.second+kkk.second+u.t;
					if(dis[kkk.first]&&dis[kkk.first]<x)continue;
					q.push({kkk.first,x});
					dis[kkk.first]=min(dis[kkk.first],x);
				}
			}
		}
		return 0;
	}
	signed main()
	{
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
		for(int i=1;i<=n;i++)
		{
			int x,t,k;
			scanf("%lld",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%lld%lld",&x,&t);
				g[i].push_back({x,t});
				gg[x].push_back({i,t});
			}
		}
		while(q--)
		{
			int u,v;
			scanf("%lld%lld",&u,&v);
			int ans=1e18;
			for(auto a:gg[u])
				for(auto b:gg[v])
					ans=min(ans,S(a.first,b.first)+a.second+b.second);
			printf("%lld\n",ans+w[u]+w[v]);
		}
		return 0;
	}
}
signed main()
{
	did::main();
	return 0;
}
/*
Ê±¼äO(???),¹À·Ö48
*/
