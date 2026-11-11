#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int c, T, n, k;
vector<int> g[1000006];
bool choose[1000006];
int fa[1000006];
bool vis[1000006];
int dis[1000006];
int cnt[1000006];
int ans = 1e9;
int find(int x)
{
	if (fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	int fx = fa[x], fy = fa[y];
	if (fx != fy)
		fa[fx] = fy;
}
bool check()
{
	for (int i = 1; i <= n; i++)
		fa[i] = i, vis[i] = 0, cnt[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] || !choose[i])
			continue;
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		while (!q.empty())
		{
			int nw = q.front();
			q.pop();
			for (int nxt : g[nw])
			{
				if (vis[nxt] || !choose[nxt])
					continue;
				q.push(nxt);
				vis[nxt] = 1;
				merge(nxt, i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (choose[i])
			fa[i] = find(i);
	for (int i = 1; i <= n; i++)
		if (choose[i])
			cnt[fa[i]]++;
	int k = 0;
	for (int i = 1; i <= n; i++)
		if (choose[i] && cnt[i])
			k++;
	return k <= 2;
}
void solve()
{
	for (int i = 1; i <= n; i++)
		fa[i] = i, vis[i] = 0, cnt[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] || !choose[i])
			continue;
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		while (!q.empty())
		{
			int nw = q.front();
			q.pop();
			for (int nxt : g[nw])
			{
				if (vis[nxt] || !choose[nxt])
					continue;
				q.push(nxt);
				vis[nxt] = 1;
				merge(nxt, i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (choose[i])
			fa[i] = find(i);
	for (int i = 1; i <= n; i++)
		if (choose[i])
			cnt[fa[i]]++;
	int k = 0;
	for (int i = 1; i <= n; i++)
		if (choose[i] && cnt[i])
			k++;
	if (k > 2)
		return ;
		
		
		
	int st = 0;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = 1e9, vis[i] = 0;
		if (choose[i])
			st = i;
	}
	queue<int> q;
	q.push(st);
	vis[st] = 1, dis[st] = 0;
	while (!q.empty())
	{
		int nw = q.front();
		q.pop();
		for (int nxt : g[nw])
		{
			if (vis[nxt] || !choose[nxt])
				continue;
			q.push(nxt);
			vis[nxt] = 1;
			dis[nxt] = dis[nw] + 1;
		}
	}
	int far = 0, mxdis = 0;
	for (int i = 1; i <= n; i++)
		if (choose[i] && vis[i])
			if (mxdis < dis[i])
				mxdis = dis[i], far = i;
	st = far;
	for (int i = 1; i <= n; i++)
		dis[i] = 1e9, vis[i] = 0;
	q.push(st);
	vis[st] = 1, dis[st] = 0;
	while (!q.empty())
	{
		int nw = q.front();
		q.pop();
		for (int nxt : g[nw])
		{
			if (vis[nxt] || !choose[nxt])
				continue;
			q.push(nxt);
			vis[nxt] = 1;
			dis[nxt] = dis[nw] + 1;
		}
	}
	for (int i = 1; i <= n; i++)
		if (choose[i] && vis[i])
			if (mxdis < dis[i])
				mxdis = dis[i], far = i;
	ans = min(ans, mxdis);
	if (k == 1)
		return ;
	
	
	
	for (int i = 1; i <= n; i++)
		if (choose[i] && fa[i] != fa[st])
		{
			st = i;
			break;
		}
	for (int i = 1; i <= n; i++)
		dis[i] = 1e9, vis[i] = 0;
	q.push(st);
	vis[st] = 1, dis[st] = 0;
	while (!q.empty())
	{
		int nw = q.front();
		q.pop();
		for (int nxt : g[nw])
		{
			if (vis[nxt] || !choose[nxt])
				continue;
			q.push(nxt);
			vis[nxt] = 1;
			dis[nxt] = dis[nw] + 1;
		}
	}
	far = 0, mxdis = 0;
	for (int i = 1; i <= n; i++)
		if (choose[i] && vis[i])
			if (mxdis < dis[i])
				mxdis = dis[i], far = i;
	st = far;
	for (int i = 1; i <= n; i++)
		dis[i] = 1e9, vis[i] = 0;
	q.push(st);
	vis[st] = 1, dis[st] = 0;
	while (!q.empty())
	{
		int nw = q.front();
		q.pop();
		for (int nxt : g[nw])
		{
			if (vis[nxt] || !choose[nxt])
				continue;
			q.push(nxt);
			vis[nxt] = 1;
			dis[nxt] = dis[nw] + 1;
		}
	}
	for (int i = 1; i <= n; i++)
		if (choose[i] && vis[i])
			if (mxdis < dis[i])
				mxdis = dis[i], far = i;
	ans = min(ans, mxdis);
}
void dfs(int now, int cs)
{
	if (cs > k)
		return ;
	if (now == n + 1)
	{
		if (cs == k && check())
		{
			solve();
		}
		return ;
	}
	choose[now] = 1;
	dfs(now + 1, cs + 1);
	choose[now] = 0;
	dfs(now + 1, cs);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> k;
		dfs(1, 0);
		cout << ans << endl;
		ans = 1e9;
	}
} 
