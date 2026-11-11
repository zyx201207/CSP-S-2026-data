#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
#define lb(x) (x&-x)
using namespace std;
const int maxn=5e3+10;
const int maxm=1e6+10;
const int INF=1e18;
const int mod=998244353;
int c,T,n,k,u,v,fa[maxn],f[maxn],dis[maxn][maxn],ans;
vector <int> g[maxn];
pii dep[maxn];
void dfs(int x,int F)
{
	fa[x]=F;
	dep[x]=mpi(dep[F].fi+1,x);
	for (auto y:g[x]) if (y!=F) dfs(y,x); 
}
void dfs2(int x,int t,int tt)
{
	if (x>n)
	{
		if (t!=2||tt!=k) return;
//		for (int i=1;i<=n;i++) cout << f[i];
//		cout << "\n";
		int mx=0;
		for (int i=1;i<=n;i++)
		{
			int mn=INF;
			for (int j=1;j<=n;j++) if (f[j]) mn=min(mn,dis[i][j]);
			mx=max(mx,mn); 
		}
		ans=min(ans,mx);
//		cout << mx << "\n";
		return;
	}
	int u=dep[x].se;
	if ((f[fa[u]]||t<2)&&tt<k)
	{
		f[u]=1;
		dfs2(x+1,t+(!f[fa[u]]),tt+1);
		f[u]=0;
	}
	dfs2(x+1,t,tt);
}
void solve()
{
	ans=INF;
	cin >> n >> k;
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dis[i][j]=INF;
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<n;i++) cin >> u >> v,g[u].push_back(v),g[v].push_back(u),dis[u][v]=dis[v][u]=1;
	for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(1,0);
	sort(dep+1,dep+n+1);
	dfs2(1,0,0);
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while (T--) solve();
	return 0;
}

