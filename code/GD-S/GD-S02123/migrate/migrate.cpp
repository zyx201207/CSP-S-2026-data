#include<bits/stdc++.h>
using namespace std;
int c, t;
int n;
long long d, a[2000010];
int h[2000010], nxt[2000010], to[2000010], ct;
void add(int u, int v)
{
	to[++ct] = v;
	nxt[ct] = h[u];
	h[u] = ct;
}
bool vis[2000010];
int cnt[2000010];
bool ck(int s, int j)
{
	memset(cnt, 0, sizeof cnt);
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u]; i; i = nxt[i])
		{
			int v = to[i];
			if(vis[v] == 0) cnt[v]++, q.push(v);
		}
	}
	return cnt[j] == 2;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--)
	{
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++) scanf("%lld", a+i);
		for(int i = 1; i < n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(a[j] - a[i] <= d) 
				{
					add(i, j);
					add(j, i);
				}
			}
		}
		int ans = 0;
		for(int i = 1; i < n; i++)
			for(int j = i + 1; j <= n; j++)
				ans += ck(i, j);
		printf("%d\n", ans);
	}
	return 0;
} 
