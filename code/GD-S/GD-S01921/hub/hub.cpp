#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,vis[1000001],dis[1000001],ans;
struct Graph
{
	int head[1000001],nxt[2000001],e[2000001],id;
	inline void add(int u,int v) { id++,nxt[id]=head[u],e[id]=v,head[u]=id; }
	void clear(int n)
	{
		for(int i=1;i<=n;i++) head[i]=0;
		id=0;
	}
}g;
void dfs1(int u,int x)
{
	vis[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]) if(!vis[g.e[i]]&&((x>>g.e[i]-1)&1)) dfs1(g.e[i],x);
}
void dfs2(int u,int f) { for(int i=g.head[u];i;i=g.nxt[i]) if(g.e[i]!=f) dis[g.e[i]]=min(dis[g.e[i]],dis[u]+1),dfs2(g.e[i],u); }
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) if(((x>>i-1)&1)&&!vis[i]) dfs1(i,x),cnt++;
	return cnt<=2;
}
int calc(int x)
{
	int ret=0;
	for(int i=1;i<=n;i++) dis[i]=!((x>>i-1)&1)*(n-1);
	for(int i=1;i<=n;i++) if((x>>i-1)&1) dfs2(i,0);
	for(int i=1;i<=n;i++) ret=max(ret,dis[i]);
	return ret;
}
void solve()
{
	cin>>n>>k,ans=n-1;
	for(int i=1;i<n;i++) cin>>x>>y,g.add(x,y),g.add(y,x);
	for(int i=0;i<(1<<n);i++) if(__builtin_popcount(i)==k&&check(i)) ans=min(ans,calc(i));
	cout<<ans<<'\n',g.clear(n);
}
int main()
{
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
}
