#include<bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3f
#define rep(i,a,b,g) for(LL i=a;i<=b;i+=g)
#define repn(i,a,b,g) for(LL i=a;i<b;i+=g)
using namespace std;
LL n,k,d[1000010],mc;
bool ch[1000010],vis[1000010];
vector<LL>e[1000010];
void dfs3(LL u,LL fa)
{
	if(ch[u])d[u]=0;
	else
	{
		d[u]=min(d[u],d[fa]+1);
	}
	for(LL i:e[u])
	{
		if(i!=fa)dfs3(i,u);
	}
}
void dfs2(LL u)
{
	vis[u]=1;
	for(LL i:e[u])
	{
		if(!vis[i]&&ch[i])dfs2(i);
	}
}
void dfs1(LL u,LL cs)
{
	if(u==n+1)
	{
		if(cs!=k)return;
		rep(i,1,n,1)vis[i]=0;
		LL su=0,t1=0,t2=0;
		rep(i,1,n,1)
		{
			if(!vis[i]&&ch[i])
			{
				su++;
				if(su>2)return;
				if(!su)t1=i;
				else t2=i;
				dfs2(i);
			}
		}
		rep(i,1,n,1)d[i]=INF;
		dfs3(t1,0);
		LL tt=0;
		rep(i,1,n,1)
		{
			tt=max(tt,d[i]);
		}
		mc=min(mc,tt);
		if(t2)
		{
			rep(i,1,n,1)d[i]=INF;
			dfs3(t2,0);
			tt=0;
			rep(i,1,n,1)
			{
				tt=max(tt,d[i]);
			}
			mc=min(mc,tt);
		}
		return;
	}
	dfs1(u+1,cs);
	ch[u]=1;
	dfs1(u+1,cs+1);
	ch[u]=0;
}
void sol()
{
	cin>>n>>k;
	mc=INF;
	rep(i,1,n,1)e[i].clear();
	LL u,v;
	repn(i,1,n,1)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	cout<<mc<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL T;
	cin>>T>>T;
	while(T--)sol();
	return 0;
}
