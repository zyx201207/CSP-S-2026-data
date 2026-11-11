#include <bits/stdc++.h>
using namespace std;

int c,t,n,k,f[1000005],ans,dis[1000005];
vector <int> g[1000005];
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	dis[s] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto y:g[x])
		{
			if (f[y] == 1 && dis[y] == 0)
			{
				dis[y] = 1;
				q.push(y);
			}
		}
	}
}
void dfs(int x,int cnt)
{
	if (x == n+1)
	{
		if (cnt != k) return;
		int num = 0;
		memset(dis,0,sizeof dis);
		for (int i = 1;i <= n;i++)
		{
			if (f[i] == 0) continue;
			if (dis[i] != 0) continue;
			num++;
			bfs(i);
		}
		if (num > 2) return;
		queue <int> q;
		memset(dis,0x3f,sizeof dis);
		for (int i = 1;i <= n;i++)
		{
			if (f[i] == 1)
			{
				q.push(i);
				dis[i] = 0;
			}
		}
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (auto y:g[x])
			{
				if (dis[y] > dis[x]+1)
				{
					dis[y] = dis[x]+1;
					q.push(y);
				}
			}
		}
		int mx = 0;
		for (int i = 1;i <= n;i++) mx = max(mx,dis[i]);
		ans = min(ans,mx);
		return;
	}
	f[x] = 1;
	dfs(x+1,cnt+1);
	f[x] = 0;
	dfs(x+1,cnt);
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1;i <= n;i++) g[i].clear();
		ans = n;
		for (int i = 1;i < n;i++)
		{
			int x,y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		cout << ans << "\n";
	}
	
	return 0;
}
