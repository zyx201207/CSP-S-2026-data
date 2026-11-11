#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int c, n, m, d, q, w[500005];
ll dis[505][505];
vector<pii> v[500005];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			int a, t;
			cin >> a >> t;
			v[a].push_back(make_pair(i, t));
		}
	}
	memset(dis, 0x3f3f3f3f, sizeof dis);
	for(int i=1;i<=m;i++)
	{
		int sz = v[i].size();
		for(int p=0;p+1<sz;p++)
		{
			for(int q=p+1;q<sz;q++)
			{
				int s = v[i][p].first, t = v[i][q].first;
				dis[s][t] = dis[t][s] = v[i][p].second + v[i][q].second;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		ll ans = 9e18;
		for(pii i : v[x])
		{
			for(pii j : v[y])
			{
				ans = min(ans, dis[i.first][j.first] + i.second + j.second);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
