#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 505,M = 5e5 + 5;
int c,n,m,d,q;
vector <pair<int,int> > g[N];
vector <pair<int,int> > g2[M];

int w[N][N];
int f[N][N];
int ww[M];
int k[N];

signed main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%lld",&ww[i]);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j = 1;j <= k[i];j++)
		{
			int a,t;
			scanf("%lld%lld",&a,&t);
			g[i].push_back({a,t});
			g2[a].push_back({i,t});
		}
	}
	memset(w,0x3f,sizeof(w));
	for(int i = 1;i <= m;i++)
	{
		for(pair<int,int> x : g2[i]) 
		{
			for(pair<int,int> y : g2[i])
			{
				if(x == y) continue;
				int u = x.first,v = y.first;
				w[u][v] = min(w[u][v],x.second + y.second);
				w[v][u] = min(w[v][u],x.second + y.second);
			}
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
		{
			f[i][j] = w[i][j];
		}
	for(int i = 1;i <= n;i++) f[i][i] = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
	for(int i = 1;i <= q;i++)
	{
		int l,r;
		scanf("%lld%lld",&l,&r);
		int ans = 1e18;
		for(pair<int,int> x : g2[l]) 
		{
			for(pair<int,int> y : g2[r])
			{
				int u = x.first,v = y.first;
				ans = min(ans,f[u][v] + x.second + y.second);
			}
		}
		printf("%lld\n",ans + ww[l] + ww[r]);
	}
	return 0;
}
