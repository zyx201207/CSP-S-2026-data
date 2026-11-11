#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, k, u, v, dis[1000005], maxx, y, minn=1e12, jsq;
bool vis[1000005], pd[1000005];
vector<int>a[1000005], b;
priority_queue<int>q;
void dfs3(int fa, int x)
{
	pd[x]=1;
	for (int i=0; i<a[x].size(); i++)
	{
		y=a[x][i];
		if (y==fa || !vis[y])
		{
			continue;
		}
		dfs3(x, y);
	}
}
void dfs2(int fa, int x, int ans)
{
	dis[x]=ans;
	for (int i=0; i<a[x].size(); i++)
	{
		y=a[x][i];
		if (y==fa || vis[y])
		{
			continue;
		}
		dfs2(x, y, ans+1);
	}
}
void dfs(int sum, vector<int>c, int la)
{
	vector<int>t;
	t=c;
	if (sum+n-la<k)
	{
		return;
	}
	if (sum>k)
	{
		for (int i=1; i<=n; i++)
		{
			dis[i]=0;
		}
		maxx=0;
		jsq=0;
		for (int i=0; i<t.size(); i++)
		{
			pd[t[i]]=0;
		}
		for (int i=0; i<t.size(); i++)
		{
			if (!pd[t[i]])
			{
				jsq++;
				if (jsq>=3)
				{
					return;
				}
				dfs3(0, t[i]);
			}
		}
		for (int i=0; i<t.size(); i++)
		{
			dfs2(0, t[i], 0);
		}
		for (int i=1; i<=n; i++)
		{
			maxx=max(maxx, dis[i]);
		}
		minn=min(minn, maxx);
		return;
	}
	for (int i=la; i<=n; i++)
	{
		t.push_back(i);
		vis[i]=1;
		dfs(sum+1, t, i+1);
		vis[i]=0;
		t=c;
	}
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		minn=1e12;
		for (int i=1; i<=n; i++)
		{
			a[i].clear();
		}
		for (int i=1; i<n; i++)
		{
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if (c==13 || c==14)
		{
			q.push(n);
			while (k--)
			{
				int h=q.top();
				q.pop();
				h-=2;
				q.push(1);
				q.push(h/2);
				q.push(h-h/2);
			}
			cout << q.top();
			while (!q.empty())
			{
				q.pop();
			}
			continue;
		}
		dfs(1, b, 1);
		cout << minn <<'\n';
	}
	return 0;
}
