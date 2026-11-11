#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair <int, int> PII;
const int N = 3e3 + 10;
const int M = 4e6 + 10;
const int INF = 1e9 + 7;
int c, n, m, d, q, tot, ans[N][N], s[M], w[M], a[N][N], t[N][N], head[M], dis[M], vis[M];
struct edge
{
	int nxt, to, dis;
} e[M];
vector <PII> vec;
inline int read()
{
	int x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch))
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
inline void write(int x)
{
	if (x >= 10) write(x / 10);
	putchar((x % 10) ^ 48);
	return ;
}
inline void add(int u, int v, int w)
{
	e[++tot] = {head[u], v, w};
	head[u] = tot; return ;
}
inline void dijkstra()
{
	priority_queue <PII, vector <PII>, greater <PII> > q;
	for (int i = 0; i <= m * n; ++i) dis[i] = INF, vis[i] = 0;
	dis[0] = 0;
	q. push({0, 0});
	while (!q. empty())
	{
		int u = q. top(). second; q. pop();
//		cout << u << ':';
		if (vis[u]) continue;
		vis[u] = 1;
		if (u == 0)
		{
			for (PII tmp : vec)
			{
				int v = tmp. first, w = tmp. second;
//				cout << v << ' ';
				if (dis[v] > dis[u] + w)
				{
					dis[v] = dis[u] + w;
					q. push({dis[v], v});
				}
			}
//			cout << endl;
		}
		else
		{
			for (int i = head[u]; i; i = e[i]. nxt)
			{
				int v = e[i]. to;
//				cout << v << ' ';
				if (dis[v] > dis[u] + e[i]. dis)
				{
					dis[v] = dis[u] + e[i]. dis;
					q. push({dis[v], v});
				}
			}
//			cout << endl;
		}
	}
	return ;
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i)
	{
		s[i] = read();
		for (int j = 1; j <= s[i]; ++j)
		{
			a[i][j] = read();
			int x = a[i][j];
			t[x][i] = read();
		}
		for (int j = 1; j <= s[i]; ++j)
		{
			for (int k = j + 1; k <= s[i]; ++k)
			{
				add(a[i][j] + m * (i - 1), a[i][k] + m * (i - 1), t[a[i][k]][i]);
				add(a[i][k] + m * (i - 1), a[i][j] + m * (i - 1), t[a[i][j]][i]);
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = j + 1; k <= n; ++k)
			{
				if (t[i][j] && t[i][k])
				{
					add(i + m * (j - 1), i + m * (k - 1), t[i][k]);
					add(i + m * (k - 1), i + m * (j - 1), t[i][j]);
				}
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j) vec. push_back({i + m * (j - 1), t[i][j]});
		dijkstra();
		vec. clear();
		for (int j = 1; j <= m; ++j) // i -> j
		{
			ans[i][j] = INF;
			for (int k = 1; k <= n; ++k) ans[i][j] = min(ans[i][j], dis[j + m * (k - 1)]); // k ²ã 
			ans[i][j] += (w[i] + w[j]);
		}
	}
	while (q--)
	{
		int x = read(), y = read();
		write(ans[x][y]);
		putchar('\n');
	}
	return 0;
}

//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
