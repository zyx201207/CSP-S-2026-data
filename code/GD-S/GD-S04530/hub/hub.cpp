#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> tr[N];
bool vis[N], vis2[N];
int dis[N], n, k, mxdis, mxid, res;

void dfs(int u, int d, int fa)
{
	if (d > mxdis)
	{
		mxdis = d;
		mxid = u;
	}
	
	for (auto v : tr[u])
	{
		if (v == fa || vis[v]) continue;
		dfs(v, d + 1, u);
	}
} // 针对没选的点组成的若干连通块求直径 

void dfs2(int u)
{
	for (auto v : tr[u])
	{
		if (!vis[v] || vis2[v]) continue; // 没选/选了且遍历过 
		vis2[v] = true;
		dfs2(v);
	}
} // 针对已选的点，求连通块数量

void check()
{
	for (int i = 1; i <= n; i++) dis[i] = 0; // 初始化 
	
	int cntscc = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] || vis2[i]) continue; // 没选的/选了且遍历过 
		cntscc++;
		dfs2(i);
	}
	if (cntscc > 2) return;
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue; // 选了/没选的且遍历过
		mxdis = 0;
		mxid = i; 
		dfs(i, 0, 0);
		mxdis = 0;
		dfs(mxid, 0, 0);
		ans = max(mxdis, ans);
	}
	
	res = min(ans, res);
}

void DFS(int pos, int cnt)
{
	if (cnt == k)
	{
		check();
		return;
	}
	
	if (cnt + n - pos + 1 < k) return;
	vis[pos] = true;
	DFS(pos + 1, cnt + 1);
	vis[pos] = false;
	DFS(pos + 1, cnt);
} // 选取点 

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, T;
	cin >> c >> T;
	
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) vis[i] = 0;
		
		for (int i = 1; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			tr[u].push_back(v);
			tr[v].push_back(u);
		}
		
		res = 1e9;
		DFS(1, 0);
		cout << res << "\n"; 
	}
	
	return 0;
}


