#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef pair<int, int> PII;
#define x first
#define y second
int n, k, d[N], st[N];
vector<int> G[N];
void dfs(int u, int father)
{
	d[u] = 0;
	for (int j : G[u])
	{
		if (j == father)continue;
		dfs(j, u);
		d[u] = max(d[u], d[j] + 1);
	}
}
void work()
{
	scanf("%d%d", &n, &k);
	for (int i = 1, a, b; i < n; i ++)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int res = n - 1;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i + 1, c = 2; j <= n; j ++)
		{
			priority_queue<PII> q;
			dfs(i, i);
			dfs(j, j);
			st[i] = st[j] = 1;
			for (int k : G[i])q.push({d[k], k});
			for (int k : G[j])q.push({d[k], k});
			while(q.size())
			{
				PII U = q.top();
				int u = U.y;
				q.pop();
				if ((++ c) > k)break;
				for (int k : G[u])
				{
					if (!st[k])
					{
						q.push({d[k], k});
						st[k] = 1;
					}
				}
			}
			res = min(res, q.top().x);
			for (int k = 1; k <= n; k ++)st[k] = 0;
		}
	}
	printf("%d\n", res);
	for (int i = 1; i <= n; i ++)G[i].clear();
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	while (T --)work();
    return 0;
}
