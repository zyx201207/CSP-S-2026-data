#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
#define lb(x) (x&-x)
using namespace std;
const int maxn=5e5+10;
const int maxm=5e2+10;
const int INF=1e18;
const int mod=998244353;
int c,n,m,d,q,w[maxn],f[maxm][maxm],k,a,t,x,y;
vector <pii> g[maxn];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("my.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++)
	{
		cin >> k;
		while (k--) cin >> a >> t,g[a].push_back(mpi(i,t));
	}
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		int k=g[i].size();
		for (int d1=0;d1<k;d1++) for (int d2=d1+1;d2<k;d2++)
		{
			f[g[i][d1].fi][g[i][d2].fi]=min(f[g[i][d1].fi][g[i][d2].fi],g[i][d1].se+g[i][d2].se);
			f[g[i][d2].fi][g[i][d1].fi]=min(f[g[i][d2].fi][g[i][d1].fi],g[i][d2].se+g[i][d1].se);
		}
	}
	for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=n;j++) cout << f[i][j] << " ";
//		cout << "\n";
//	}
	while (q--)
	{
		cin >> x >> y;
		int ans=INF;
		for (auto u:g[x]) for (auto v:g[y]) ans=min(ans,u.se+v.se+f[u.fi][v.fi]);
		cout << ans+w[x]+w[y] << "\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
