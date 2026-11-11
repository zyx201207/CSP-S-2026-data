#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500005],dis[1005][1005];
vector <pair<int,long long>> q[1005];
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
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	p = read();
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for (int i = 1;i <= m;i++)
	{
		w[i] = read();
	}
	for (int i = 1;i <= n;i++)
	{
		dis[i][i] = 0;
		int k = read();
		vector <int> a,b;
		for (int j = 1;j <= k;j++)
		{
			int x = read(),t = read();
			for (int k = 0;k < a.size();k++)
			{
				q[x].push_back({a[k],t + b[k]});
				q[a[k]].push_back({x,t + b[k]});
			}
			a.push_back(x);
			b.push_back(t);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		priority_queue <pair <int,long long>,vector <pair<int,long long>>, greater<>> dij;
		bool vis[1005] = {0};
		memset(dis[i],0x3f3f3f3f,sizeof(dis[i]));
		dis[i][i] = 0;
		dij.push({0,i});
		while (!dij.empty())
		{
			int u = dij.top().second;
			dij.pop();
			if (vis[u])
			{
				continue;
			}
			vis[u] = 1;
			for (int j = 0;j < q[u].size();j++)
			{
				int v = q[u][j].first;
				long long w = q[u][j].second;
				if (dis[i][v] > dis[i][u] + w)
				{
					dis[i][v] = dis[i][u] + w;
					dij.push({dis[i][v],v});
				}
			}
		}
	}
	for (int i = 1;i <= p;i++)
	{
		int u = read(),v = read();
		cout << dis[u][v] + w[u] + w[v] << '\n';	
	}
 	return 0;
}

