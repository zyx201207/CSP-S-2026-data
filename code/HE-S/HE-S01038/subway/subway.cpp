#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
int dis[505][505],w[500005];
vector<pii> v[505],g[500005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;
	cin >> C >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int c;
		cin >> c;
		for(int j = 1;j <= c;j++)
		{
			int x,y;
			cin >> x >> y;
			v[i].push_back(mk(x,y));
			g[x].push_back(mk(i,y));
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i == j)
			{
				dis[i][j] = 0;
			}
			else
			{
				dis[i][j] = 1e18;
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(auto j : v[i])
		{
			for(auto k : g[j.fi])
			{
				if(i == k.fi)
				{
					continue;
				}
				dis[i][k.fi] = min(dis[i][k.fi],k.se + j.se);
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= n;k++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		int mn = 1e18;
		for(auto i : g[x])
		{
			for(auto j : g[y])
			{
				mn = min(mn,i.se + j.se + dis[i.fi][j.fi]);
			}
		}
		cout << ans + mn << "\n";
	}
	return 0;
}
