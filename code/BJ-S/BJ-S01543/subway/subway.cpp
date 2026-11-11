#include <bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
int a[500005],dis[505][505];
struct node
{
	int y,w;
};
vector <node> g[500005];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> a[i];
	memset(dis,0x3f,sizeof dis);
	for (int i = 1;i <= n;i++)
	{
		dis[i][i] = 0;
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++) 
		{
			int x,t;
			cin >> x >> t;
			g[x].push_back({i,t});
		}
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 0;j < g[i].size();j++)
		{
			for (int k = j+1;k < g[i].size();k++)
			{
				dis[g[i][j].y][g[i][k].y] = min(dis[g[i][j].y][g[i][k].y],g[i][j].w+g[i][k].w);
				dis[g[i][k].y][g[i][j].y] = min(dis[g[i][k].y][g[i][j].y],g[i][j].w+g[i][k].w);
			}
		}
	}
	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i < k;i++)
		{
			for (int j = k+1;j <= n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int i = 1;i <= q;i++)
	{
		int x,y;
		cin >> x >> y;
		int ans = 1e18;
		for (int j = 0;j < g[x].size();j++)
		{
			for (int k = 0;k < g[y].size();k++)
			{
				ans = min(ans,dis[min(g[x][j].y,g[y][k].y)][max(g[x][j].y,g[y][k].y)]+g[x][j].w+g[y][k].w);
			}
		}
		ans += a[x]+a[y];
		cout << ans << "\n";
	}
	
	return 0;
}
