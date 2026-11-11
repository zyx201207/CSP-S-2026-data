#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505,M = 5e5 + 5;
const ll MAXN = 5e17;
int c,n,m,d,q;
ll w[M];
ll E[N][N],nx[M][21],dis[M][21],cnt[M];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++ i)cin >> w[i];
	for(int i = 1;i <= n;++ i)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= n;++ j)
		if(i != j)
		E[i][j] = MAXN;
		for(int j = 1;j <= k;++ j)
		{
			int a,t;
			cin >> a >> t;
			++ cnt[a];
			nx[a][cnt[a]] = i;
			dis[a][cnt[a]] = t;
		}
	}
	for(int k = 1;k <= m;++ k)
	{
		for(int i = 1;i <= cnt[k];++ i)
		{
			for(int j = i + 1;j <= cnt[k];++ j)
			{
				ll& u = nx[k][i];
				ll& v = nx[k][j];
				ll dt = dis[k][i] + dis[k][j];
				E[u][v] = E[v][u] = min(E[u][v],dt);
			}
		}
	}
	for(int k = 1;k <= n;++ k)
	{
		for(int i = 1;i < n;++ i)
		{
			if(i == k)continue;
			for(int j = i + 1;j <= n;++ j)
			{
				if(j == k)continue;
				E[j][i] = E[i][j] = min(E[i][j],E[i][k] + E[k][j]);
			}
		}
	}
	int xr,yr;
	ll res;
	for(int t = 1;t <= q;++ t)
	{
		cin >> xr >> yr;
		res = MAXN;
		for(int i = 1;i <= cnt[xr];++ i)
		{
			for(int j = 1;j <= cnt[yr];++ j)
			{
				res = min(res,E[nx[xr][i]][nx[yr][j]] + dis[xr][i] + dis[yr][j]);
			}
		}
		cout << res + w[xr] + w[yr] << '\n';
	}
	return 0;
}

