#include<bits/stdc++.h>
using namespace std;
#define rig register int
#define cit const int&
#define N 2000005
int c,t,n,k,cnt,ans,h[N];
bool b[N];
struct edge{ int to,nxt; }e[N];
struct que{ int id,bs,fa; }q[N];
inline void add(cit x,cit y) { e[++cnt]={y,h[x]}; h[x]=cnt; }
inline int bfs(cit d)
{
	q[1]={d,0,0};
	for(rig l=0,r=1;l++<r;)
	{
		cit u=q[l].id,bs=q[l].bs,fa=q[l].fa;
		if(b[u]) return bs;
		for(rig i=h[u];i;i=e[i].nxt)
		{
			cit v=e[i].to;
			if(v==fa) continue;
			q[++r]={v,bs+1,u};
		}
	}
}
inline void dfs(cit d,cit sum)
{
	if(d>n) return;
	if(sum==k)
	{
		rig res=0;
		for(rig i=1;i<=n;i++) res=max(res,bfs(i));
		ans=min(ans,res);
		return;
	}
	for(rig i=d+1;i<=n;i++) b[i]=1,dfs(d+1,sum+1),b[i]=0;
	dfs(d+1,sum);
}
inline void solve()
{
	cin>>n>>k; ans=INT_MAX; memset(h,0,sizeof h); cnt=0;
	for(rig i=1,x,y;i<n;i++) cin>>x>>y,add(x,y),add(y,x);
	ans=INT_MAX; dfs(1,0); cout<<ans<<'\n';
}
main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
}
