#include <bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
bool vis[1005];
int d[1005];
vector<int> e[1005];
bool check(int x)
{
	for (int i = 1;i <= x;i++)
	{
		if (!vis[i])
		{
			return 1;
		}
	}
	return 0;
}
void dfs(int x,int now)
{
	if (check(x))
	{
		for (int i = 0;i < e[now].size();i++)
		{
			int v = e[now][i];
			if (!vis[v])
			{
				vis[v] = 1;
				d[v] = d[now] + 1;
			}
			dfs(x,v);
		}
	}
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while (T--)
	{
		memset(vis,0,sizeof(vis));
		for (int i = 1;i <= 1001;i++)
		{
			e[i].clear();
		}
		cin >> n >> k;
		for (int i = 1;i <= n - 1;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		d[1] = 0;
		int maxx = -1;
		for (int i = 1;i <= n;i++)
		{
			memset(d,0,sizeof(d));
			dfs(n,i);
			maxx = -1;
			for (int j = 1;j <= n;j++)
			{
				maxx = max(maxx,d[j]);
			}
		}
		cout << maxx << endl;
	}
	return 0;
}
