#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i128 __int128_t
#define u128 __uint128_t
#define i16 short
#define u16 unsigned i16
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#ifdef int
#define i32 signed
#define u32 unsigned
#define inf (int)(1e18)
#define popc(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctzll(x)
#define clz(x) __builtin_clzll(x)
#else
#define ll long long
#define ull unsigned ll
#define inf (int)(1e9)
#define infl (ll)(1e18)
#define popc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define clz(x) __builtin_clz(x)
#define popcl(x) __builtin_popcountll(x)
#define ctzl(x) __builtin_ctzll(x)
#define clzl(x) __builtin_clzll(x)
#endif
#define push emplace
#define pb emplace_back
#define pf emplace_front
#define ppb pop_back
#define ppf pop_front
const int N=1e6+10,mod=1e9+7;
vector<int>adj[N];
int dis[110][110];
int dep[N];
int n,k;
void solve1()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=1e18;
	for(int i=1;i<=n;i++) adj[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v),adj[v].pb(u);
		dis[u][u]=dis[v][v]=0,dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int ans=1e18;
	for(int s=0;s<(1<<n);s++) if(popc(s)==k)
	{
		int cb=0;
		for(int i=1;i<=n;i++) if(s>>i-1&1) for(auto v:adj[i]) if(s>>v-1&1) cb++;
		cb/=2;
		if(cb<k-2) continue;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int td=1e18;
			for(int j=1;j<=n;j++) if(s>>j-1&1) td=min(td,dis[i][j]);
			res=max(res,td);
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	for(auto v:adj[u])
	{
		if(v==f) continue;
		dfs(v,u);
	}
}
void solve2()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) adj[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v),adj[v].pb(u);
	}
	if(n==k){cout<<0<<'\n';return;}
	int m=(n+1)/2;
	cout<<(m-k+5)/4<<'\n';
}
void solve3()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) adj[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v),adj[v].pb(u);
	}
	dfs(1,0);
	int rt=max_element(dep+1,dep+n+1)-dep;
	dfs(rt,0);
	int m=*max_element(dep+1,dep+n+1);
	cout<<max((m-k+5)/4,0ll)<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c<=3) while(t--) solve1();
	else if(13<=c&&c<=14) while(t--) solve2();
	else while(t--) solve3();
	return 0;
}
/*
只有爆搜+A 的 25pts qwq

281pts，太难了，还极有可能挂掉

关注 Shellchen 谢谢喵。
*/