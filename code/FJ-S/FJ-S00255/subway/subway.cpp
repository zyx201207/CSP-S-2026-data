#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, LL> PIL;
const int N = 5e5 + 10, M = 500 + 10;
int c, n, m, d, q;
LL w[N], f[M][M], val[N];
int head[N], to[N], ne[N], idx;

void add(int a, int b, LL c)
{
	to[idx] = b;
	val[idx] = c;
	ne[idx] = head[a];
	head[a] = idx ++;
}

void floyd()
{
	for(int k = 1;k <= n; ++ k)
		for(int i = 1;i <= n; ++ i)
			for(int j = 1;j <= n; ++ j)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	memset(head, -1, sizeof head);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m; ++ i)
		scanf("%lld", &w[i]);
	
	for(int i = 1, K;i <= n; ++ i)
	{
		scanf("%d", &K);
		for(int j = 1;j <= K; ++ j)
		{
			int a; LL t;
			scanf("%d%lld", &a, &t);
			add(a, i, t);
		}
	}
	
	memset(f, 0x3f, sizeof f);
	for(int i = 1;i <= n; ++ i)
		f[i][i] = 0;
	for(int i = 1;i <= m; ++ i)
	{
		for(int j = head[i]; ~j; j = ne[j])
			for(int k = head[i]; ~k; k = ne[k])
				if(j != k)
				{
					int u = to[j], v = to[k];
					f[u][v] = f[v][u] = min(f[u][v], val[j] + val[k]); 
				}
				
	}
	
	floyd();
	
	while(q --)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		LL ans = 1e18;
		for(int i = head[x]; ~i; i = ne[i])
			for(int j = head[y]; ~j; j = ne[j]) 
				ans = min(ans, f[to[i]][to[j]] + val[i] + val[j]);
		ans += w[x] + w[y];
		printf("%lld\n", ans);
	}
	return 0; 
}
