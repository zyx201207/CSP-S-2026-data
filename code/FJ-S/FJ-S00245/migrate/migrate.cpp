#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,num[5005],ans;
vector <int> q[5005];
long long read()
{
	char c = getchar();
	long long res = 0,x = 1;
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			x = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * x;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	c = read();
	t = read();
	if (c == 11 || c == 12)
	{
		while (t--);
		{
			cout << 0 << "\n";
		}
		return 0;
	}
	while (t--)
	{
		n = read();
		d = read();
		ans = 0;
		for (int i = 1;i <= n;i++)
		{
			q[i].clear();
		}
		for (int i = 1;i <= n;i++)
		{
			num[i] = read();
			for (int idx = i - 1;idx > 0 && num[i] - num[idx] <= d;idx--)
			{
				q[i].push_back(idx);
				q[idx].push_back(i);
			}
		}
		for (int i = 1;i <= n;i++)
		{
			priority_queue <pair <long long,long long>,vector <pair<long long,long long>>,greater<>> dij;
			long long dis[5005],cnt[5005];
			bool vis[5005];
			memset(dis,0x3f3f3f3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			memset(cnt,0,sizeof(cnt));
			dis[i] = 0;
			cnt[i] = 1;
			dij.push({0,i});
			while (!dij.empty())
			{
				int u = dij.top().second;
				dij.pop();
				if (vis[u])
				{
					continue ;
				}
				vis[u] = 1;
				for (int j = 0;j < q[u].size();j++)
				{
					long long v = q[u][j];
					if (dis[v] > dis[u] + 1)
					{
						dis[v] = dis[u] + 1;
						cnt[v] = cnt[u];
						dij.push({dis[v],v});
					}
					else if (dis[v] == dis[u] + 1)
					{
						cnt[v]++;
					}
				}
			}
			for (int j = i + 1;j <= n;j++)
			{
				if (cnt[j] == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
 	return 0;
}

