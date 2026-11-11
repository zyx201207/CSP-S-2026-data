#include <bits/stdc++.h>
using namespace std;
bool b[101], vis[101];
vector<int> d[101];
int ans, n, now;
void dfs(int x)
{
	if(vis[x])
	{
		return;
	}
	vis[x]=true;
	for(int y : d[x])
	{
		if(!b[y])
		{
			continue;
		}
		dfs(y);
	}
}
int suan(int x, int p)
{
	int maxn = 0;
	for(int y : d[x])
	{
		if(y==p)
		{
			continue;
		}
		if(b[y])
		{
			return 1;
		}
		maxn=max(maxn, suan(y, x));
	}
	return maxn+1;
}
void dfss(int x, int k)
{
	if(k<0)
	{
		return;
	}
	if(x==n+1)
	{
		now=0;
		int cnt = 0;
		for(int i = 1; i<=n; i++)
		{
			vis[i]=false;
		}
		for(int i = 1; i<=n; i++)
		{
			if(b[i] && !vis[i])
			{
				dfs(i);
				cnt++;
			}
			else
			{
				now=max(now, suan(i, 0));
			}
		}
		if(cnt>2)
		{
			return;
		}
		ans=min(ans, now);
		return;
	}
	dfss(x+1, k);
	b[x]=true;
	dfss(x+1, k-1);
	b[x]=false;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--)
	{
		ans=1e9;
		int k;
		cin >> n >> k;
		for(int i = 1; i<=n; i++)
		{
			d[i].clear();
		}
		for(int i = 1; i<n; i++)
		{
			int x, y;
			cin >> x >> y;
			d[x].push_back(y);
			d[y].push_back(x);
		}
		dfss(1, k);
		cout << ans << endl;
	}
	return 0;
}
