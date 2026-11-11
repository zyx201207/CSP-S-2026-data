#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e6+10;
LL n,m;
vector<int> e[N];
LL d[N],o[N];
LL dep[N],rt,F[N];
bool vis[N];
void bfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	if(dep[rt]<dep[u]) rt=u;
	F[u]=fa;
	for(auto v:e[u]) if(v!=fa&&!vis[v]) bfs(v,u);
}
void getRT(int u)
{
	rt=0;
	bfs(u,0);
	bfs(rt,0);
	int cnt=dep[rt]/2;
	while(cnt--) rt=F[rt];
//	printf("[%d,%d]",u,rt);
}
void dfs(int u,int fa)
{
	d[u]=0;
	for(auto v:e[u])
	{
		if(v==fa||vis[v]) continue;
		dfs(v,u);
		d[u]=max(d[u],d[v]+1);
	}
	o[d[u]]++;
//	printf("[dfs %d,%lld]",u,d[u]);
}
void solve()
{
	for(int i=1;i<=n;i++) e[i].clear();
	scanf("%lld%lld",&n,&m);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v),e[v].push_back(u);
	}
	d[0]=-1;
	LL ans=n+1;
	for(int u=1;u<=n;u++)
	{
		for(auto v:e[u])
		{
			if(u<v) continue;
			for(int i=0;i<=n;i++) o[i]=0;
			vis[v]=1; getRT(u); dfs(rt,0); o[d[rt]]--; vis[v]=0;
//			for(int i=0;i<=n;i++) printf("[%lld]",o[i]); printf("\n");
			vis[u]=1; getRT(v); dfs(rt,0); o[d[rt]]--; vis[u]=0;
			LL sum=0;
//			for(int i=0;i<=n;i++) printf("[%lld]",o[i]); printf("\n");
			for(LL i=n;i>=1;i--)
			{
				sum+=o[i];
				if(sum+2<=m) ans=min(ans,i);
			}
//			printf("[%lld]",ans);
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	LL c,T; scanf("%lld%lld",&c,&T);
	while(T--) solve();
	return 0;
}
