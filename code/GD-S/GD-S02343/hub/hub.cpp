#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, cnt, mn, dist, ans;
bool is[15], vis[15];
vector<int> v[15];
queue<pair<int, int>> que, q;
int d(int u, int uu)
{
	if (u==uu)
	{
		return 0;
	}
	//memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	q.push({u, 0});
	vis[u]=1;
	while (!q.empty())
	{
		int o=q.front().first, b=q.front().second;
		q.pop();
		for (auto x : v[o])
		{
			if (!vis[x])
			{
				vis[x]=1;
				if (x==uu)
				{
					while (!q.empty())
					{
						q.pop();
					}
					return b+1;
				}
				q.push({x, b+1});
			}
		}
	}
}
int main()
{
	cin >> c >> t;
	while (t--)
	{
		for (int i=1; i<=n; i++)
		{
			v[i].clear();
		}
		cin >> n >> k;
		for (int i=1; i<n; i++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i=1; i<(1<<n); i++)
		{
			ans=1e9;
			memset(is, 0, sizeof(is));
			memset(vis, 0, sizeof(vis));
			cnt=0;
			for (int j=0; j<n; j++)
			{
				is[j]=(i&(1<<j));
			}
			q.push({1, is[1]});
			vis[1]=1;
			while (!q.empty())
			{
				int u=q.front().first, b=q.front().second;
				q.pop();
				for (auto x : v[u])
				{
					if (!vis[x])
					{
						vis[x]=1;
						if (is[x]==1 && is[u]==0)
						{
							cnt++;
						}
						que.push({x, is[x]});
					}
				}
			}
			if (cnt==2)
			{
				for (int i1=1; i1<=n; i1++)
				{
					for (int j1=0; j1<n; j1++)
					{
						if (is[j1])
						{
					 		int dd=d(i1, j1);
							dist=max(dd, dist);
						}
					}
				}
				ans=min(ans, dist);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
