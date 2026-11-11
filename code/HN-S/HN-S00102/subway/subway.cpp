#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k[505];
struct node
{
	int x;
	long long t;
};
long long w[500005];
vector <node> v[500005];
long long dis[505][505];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) dis[i][j] = 1e18;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			int a;
			long long t;
			cin >> a >> t;
			v[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int g = 0;g < v[i].size();g++)
		{
			for(int h = g + 1;h < v[i].size();h++)
			{
				node w = v[i][g],e = v[i][h];
				long long t = dis[w.x][e.x];
				dis[w.x][e.x] = dis[e.x][w.x] = min(t,w.t + e.t);
			}
		}
	}
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q > 0)
	{
		q--;
		int x,y;
		cin >> x >> y;
		long long ans = 1e18;
		for(int g = 0;g < v[x].size();g++)
		{
			for(int h = 0;h < v[y].size();h++)
			{
				node w = v[x][g],e = v[y][h];
				if(w.x == e.x)
				{
					ans = min(ans,w.t + e.t);
				}
				ans = min(ans,w.t + e.t + dis[w.x][e.x]);
			}
		}
//		cout << w[x] << "|" << w[y] << '\n';
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
