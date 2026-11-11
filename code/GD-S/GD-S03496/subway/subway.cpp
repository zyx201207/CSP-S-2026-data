#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, p, w[500005], k, b, bb, tt, x, y, dis[500005], s, sum, ttt, diss[500005];
struct aa
{
	int id, v, t, qq;
};
struct bbb
{
	int ss, sl, sq;
};
queue<bbb>q;
vector<aa>a[500005];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> p;
	for (int i=1; i<=m; i++)
	{
		cin >> w[i];
	}
	for (int i=1; i<=n; i++)
	{
		cin >> k;
		cin >> bb >> ttt;
		for (int j=2; j<=k; j++)
		{
			cin >> b >> tt;
			a[b].push_back({i, bb, tt, ttt});
			a[bb].push_back({i, b, ttt, tt});
			ttt=tt;
			bb=b;
		}
	}
	while (p--)
	{
		cin >> x >> y;
		for (int i=1; i<=m; i++)
		{
			dis[i]=1e12;
			diss[i]=1e12;
		}
		dis[x]=w[x];
		q.push({x, 0, 0});
		while(!q.empty())
		{
			bbb s=q.front();
			q.pop();
			for (int i=0; i<a[s.ss].size(); i++)
			{
				sum=0;
				if (s.sl==0)
				{
					sum=a[s.ss][i].t;
				}
				else if (s.sl!=a[s.ss][i].id)
				{
					sum=a[s.ss][i].t+s.sq;
				}
				if (dis[a[s.ss][i].v]>dis[s.ss]+sum)
				{
					dis[a[s.ss][i].v]=dis[s.ss]+sum;
					if (diss[a[s.ss][i].v]>dis[a[s.ss][i].v]+a[s.ss][i].qq)
					{
						diss[a[s.ss][i].v]=dis[a[s.ss][i].v]+a[s.ss][i].qq;
					}
					q.push({a[s.ss][i].v, a[s.ss][i].id, a[s.ss][i].qq});
				}
			}
		}
		cout << diss[y]+w[y] <<'\n';
	}
	return 0;
}
