#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2e6 + 10;
int c, t, n, k, ans;
int head[N], to[N << 1], ne[N << 1], idx;
int w[N], fa[N];
bool vis[N], st[N], scc[N];

int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void add(int a, int b)
{
	to[idx] = b;
	ne[idx] = head[a];
	head[a] = idx ++;
}

void dfs(int p, int cnt)
{
	if(cnt > k)
		return ;
	if(p == n + 1)
	{
		int x = 0;
		for(int i = 1;i <= n; ++ i)
			fa[i] = i, scc[i] = 0;
		for(int i = 1;i <= n; ++ i)
			if(vis[i])
			{
				x = i;
				for(int j = head[i]; ~j; j = ne[j])
					if(vis[to[j]])
						fa[find(to[j])] = find(i);
			}
		int cnt = 1;
		scc[find(x)] = true;
		for(int i = 1;i <= n; ++ i)
			if(vis[i] && !scc[find(i)])
				cnt ++, scc[find(i)] = true;
		if(cnt > 2) return ;
		memset(w, 0x3f, sizeof w);
		queue<int> q;
		for(int i = 1;i <= n; ++ i)
			if(vis[i]) q.push(i), w[i] = 0, st[i] = true;
		while(q.size())
		{
			int u = q.front();
			q.pop(), st[u] = false;
			for(int i = head[u]; ~i; i = ne[i])
			{
				int v = to[i];
				if(w[v] > w[u] + 1)
				{
					w[v] = w[u] + 1;
					if(!st[v]) q.push(v), st[v] = true;
				}
			}
		}
		int res = 0;
		for(int i = 1;i <= n; ++ i)
			res = max(res, w[i]);
		ans = min(ans, res);
		return ;
	}
	vis[p] = true;
	dfs(p + 1, cnt + 1);
	vis[p] = false;
	dfs(p + 1, cnt);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while(t --)
	{
		memset(head, -1, sizeof head);
		ans = 1e9, idx = 0;
		scanf("%d%d", &n, &k);
		for(int i = 1;i < n; ++ i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v), add(v, u);
		}
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0; 
}
