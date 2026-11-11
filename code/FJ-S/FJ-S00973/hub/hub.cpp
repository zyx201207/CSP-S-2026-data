#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e6 + 10, M = N * 2;

int h[N], e[M], ne[M], idx;
int f[N], ag[N]; bool st[N];
int fa[N][30], dep[N];

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void write(int x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x <= 9) {putchar(x + '0'); return;}
	write(x / 10); putchar(x % 10 + '0');
}

void add(int a, int b) {e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;}

void dfs(int u, int fat)
{
	fa[u][0] = fat, dep[u] = dep[fat] + 1;
	for (int k = 1; k <= 20; k ++ ) fa[u][k] = fa[fa[u][k - 1]][k - 1];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == fat) continue;
		dfs(j, u);
	}
}

int LCA(int a, int b)
{
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = 20; ~k; k -- )
	{
		if (dep[fa[a][k]] >= dep[b]) a = fa[a][k];
	}
	if (a == b) return a;
	for (int k = 20; ~k; k -- )
	{
		if (fa[a][k] != fa[b][k]) a = fa[a][k], b = fa[b][k];
	}
	return fa[a][0];
}

int getdist(int a, int b)
{
	int d = LCA(a, b);
	return dep[a] + dep[b] - dep[d] * 2;
}

int get1(int x)
{
	int res = 0;
	while (x) res ++ , x -= (x & -x);
	return res;
}

int find(int x)
{
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}

void merge(int a, int b)
{
	int fa = find(a), fb = find(b);
	if (fa == fb) return;
	f[fa] = fb;
}

void solve(int C)
{
	int n = read(), K = read();
	for (int i = 1; i <= n; i ++ ) h[i] = -1; idx = 0;
	for (int i = 1, a, b; i < n; i ++ )
	{
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	dfs(1, 0);
//	if (C >= 1 && C <= 3)
//	{
		int res = n + 1;
		for (int s = 0; s < (1 << n); s ++ )
		{
			if (get1(s) != K) continue;
			for (int i = 1; i <= n; i ++ ) f[i] = i, st[i] = false;
			for (int i = 1; i <= n; i ++ )
			{
				if (!((s >> (i - 1)) & 1)) continue;
				for (int j = h[i]; ~j; j = ne[j])
				{
					int k = e[j];
					if (!((s >> (k - 1)) & 1)) continue;
					merge(i, k);
				}
			}
			int cntb = 0, tot = 0;
			for (int i = 1; i <= n; i ++ )
			{
				if (!((s >> (i - 1)) & 1)) continue;
				int fi = find(i); ag[ ++ tot] = i;
				if (!st[fi]) st[fi] = true, cntb ++ ;
			}
			if (cntb > 2) continue;
			int mx = 0;
			for (int i = 1; i <= n; i ++ )
			{
				int mn = n + 1;
				for (int j = 1; j <= K; j ++ ) mn = min(mn, getdist(i, ag[j]));
				mx = max(mx, mn);
			}
			res = min(res, mx);
		}
		printf("%d\n", res);
		return;
//	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int C = read(), T = read();
	while (T -- ) solve(C);
	return 0;
}
