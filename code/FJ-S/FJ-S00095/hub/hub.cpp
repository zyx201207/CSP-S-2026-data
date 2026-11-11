#include <cstring>
#include <iostream>

using namespace std;

const int N = 4010;

int p[N];
int n, m;
int S[N];
bool sign[N];
int ans = 0x3f3f3f3f;
int depth[N], fa[N][21];
int h[N], e[N], ne[N], idx;

inline void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

inline int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

inline void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	p[a] = b;
}

inline int lca(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
		
	for (int k = 20; k >= 0; -- k )
		if (depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	
	if (a == b) return a;
	
	for (int k = 20; k >= 0; -- k )
		if(fa[a][k] != fa[b][k])
			a = fa[a][k], b = fa[b][k];
	
	return fa[a][0];
}

inline int check()
{
	for (int i = 1; i <= n; ++ i )
		p[i] = i;
	for (int i = 1; i <= n; ++ i )
		if (sign[i])
		{
			for (int j = h[i]; ~j; j = ne[j])
			{
				int k = e[j];
				if (sign[k]) merge(i, k);
			}
			S[ ++ S[0] ] = i;
		}
	
	int cnt = 0;
	for (int i = 1; i <= n; ++ i )
		if (sign[i] && p[i] == i)
			cnt ++ ;
	
	if (cnt > 2) return 0x3f3f3f3f;
	
	int res = 0;
	for (int i = 1; i <= n; ++ i )
	{
		if (sign[i]) continue;
		
		int cur = 0x3f3f3f3f;
		for (int j = 1; j <= S[0]; ++ j )
			cur = min(cur, depth[S[j]] + depth[i] - 2 * depth[lca(S[j], i)]);
		
		res = max(res, cur);
	}
	
	return res;
}

inline void dfs(int dep, int sum, int last)
{
	if (dep == n + 1)
	{
		if (sum == m) ans = min(ans, check());
		return;
	}
	
	dfs(dep + 1, sum, last);
	for (int i = last + 1; i <= n; ++ i )
	{
		if (sign[i]) continue;
		
		sign[i] = true;
		dfs(dep + 1, sum + 1, i);
		sign[i] = false;
	}
}

inline void init(int u, int father, int dep)
{
	depth[u] = dep;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == father) continue;
		
		fa[j][0] = u;
		for (int k = 1; k <= 20; ++ k )
			fa[j][k] = fa[fa[j][k - 1]][k - 1];
		
		init(j, u, dep + 1);
	}
}

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	
	return x * f;
}

inline void write(int x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c = read(), T = read();
	
	while (T -- )
	{
		memset(h, -1, sizeof h);
		idx = 0, ans = 0x3f3f3f3f;
		
		n = read(), m = read();
		for (int i = 1; i <= n; ++i )
		{
			int a = read(), b = read();
			add(a, b), add(b, a);
		}
		
		init(1, 0, 1);
		
		dfs(1, 0, 0);
		
		write(ans), putchar('\n');
	}
	
	return 0;
}
