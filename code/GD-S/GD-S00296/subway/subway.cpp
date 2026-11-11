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
const int N=5e5+10,mod=1e9+7;
vector<pii>od[N];
int a[N];
int dis[510][510];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			od[v].pb(i,w);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) for(int j=0;j<od[i].size();j++) for(int k=j+1;k<od[i].size();k++)
	{
		int u=od[i][j].fi,v=od[i][k].fi,w=od[i][j].se+od[i][k].se;
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto u:od[x]) for(auto v:od[y]) ans=min(ans,u.se+v.se+dis[u.fi][v.fi]);
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}
/*
nice problem。

先把地铁线路虚点之间的两两距离求出来，Floyd 可以做到 O(n^3)。

每次询问枚举取哪两条即可。

总复杂度 $O(md^2+n^3+qd^2)$，瓶颈似乎在 md^2 但是跑不满，可以过吗 qwq。

14:58 AC，看眼数据

怎么 d=2？？？还得自己造一组

0.35 秒左右，应该没问题了
*/