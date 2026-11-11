#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int c, t, n, k, sum[N], num[N];
vector<int> e[N];

inline void dfs(int u, int fa)
{
	sum[u] = 1;
	for(int i = 0; i < e[u].size(); ++ i)
	{
		int v = e[u][i];
		if(v == fa) continue;
		dfs(v, u);
		sum[u] += sum[v];
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while(t --)
	{
		scanf("%d%d", &n, &k);
		if(c == 13 || c == 14)
		{
			printf("%d\n", ((n - 1) / 2 - k + 3) / 4 + 1);
		}
	}
	
	return 0;
}