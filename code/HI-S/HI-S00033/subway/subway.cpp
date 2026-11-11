#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ci=const int;
#define ft first
#define sd second
ci N=2e6+5;
namespace Qwq
{
	int c,n,m,d,q;
	ll f[N];
	int head[N],nxt[N<<1],tot,vis[N],to[N];
	ll val[N<<1];
	int zt[N],ck[N],cnt,zz[N];
	void add(int x,int y,ll z)
	{
		to[++tot]=y;
		val[tot]=z;
		nxt[tot]=head[x];
		head[x]=tot;
	}
	void dijkstra(int s)
	{
		int i;
		for(i=1;i<=cnt;i++) f[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		f[s]=0;
		q.push({0,s});
		while(q.size())
		{
			int x=q.top().sd;
			q.pop();
			if(vis[x]) continue;
			vis[x]=1;
			for(i=head[x];i;i=nxt[i])
			{
				int y=to[i];
				if(f[x]+val[i]<f[y])
				{
					f[y]=f[x]+val[i];
					q.push(make_pair(f[y],y));
				}
			}
		}
	}
	void mian()
	{
		int i,j;
		cin>>c>>n>>m>>d>>q;
		cnt=m;
		for(i=1;i<=m;i++)
		{
			ll w;
			cin>>w;
			zt[i]=++cnt;
			ck[i]=++cnt;
			add(zt[i],ck[i],w);
			add(ck[i],zt[i],w);
		}
		for(i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			int lst;
			for(j=1;j<=k;j++)
			{
				int a;
				ll t;
				cin>>a>>t;
				zz[a]=++cnt;
				if(j!=1)
				{
					add(lst,zz[a],0);add(zz[a],lst,0);
				}
				add(zz[a],zt[a],t);add(zt[a],zz[a],t);
				lst=zz[a];
			}
		}
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			dijkstra(ck[u]);
			cout<<f[ck[v]]<<'\n';
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	Qwq::mian();
	return 0;
}
