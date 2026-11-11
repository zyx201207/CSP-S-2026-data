#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <random>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;
inline int read() {int x; return scanf("%d", &x), x;}
namespace MYJBCHX
{
	const int N = 1e6;
	int n, k;
	int root;
	struct edge
	{
		int v, ne;
	} e[2 * N + 5];
	int h[N + 5], idx;
	inline void connect(int u, int v) {e[idx] = edge{v, h[u]}, h[u] = idx ++ ;}
	int dep[N + 5], dis[N + 5];
	void init(int u, int fa)
	{
		dep[u] = 0;
		dis[u] = dis[fa] + 1;
		for (int i = h[u]; ~i; i = e[i].ne)
		{
			int v = e[i].v;
			if (v == fa) continue;
			init(v, u);
			dep[u] = std :: max(dep[u], dep[v] + 1);
		}
	}
	int path[N + 5], rnw;
	bool find_path(int u, int fa, int t)
	{
		path[ ++ rnw] = u;
		if (u == t) return 1;
		for (int i = h[u]; ~i; i = e[i].ne)
		{
			int v = e[i].v;
			if (v == fa) continue;
			if (find_path(v, u, t)) return 1;
		}
		rnw -- ;
		return 0;
	}
	int a[N + 5], tot;
	int dfs(int u, int fa, int mid)
	{
		if (dep[u] < mid) return 0;
		int res = 1;
		for (int i = h[u]; ~i; i = e[i].ne)
		{
			int v = e[i].v;
			if (v == fa) continue;
			res += dfs(v, u, mid);
		}
		return res;
	}
	int find(int u, int fa, int mid)
	{
		// printf("111 %d\n", u);
		a[ ++ tot] = 0;
		int son = 0;
		for (int i = h[u]; ~i; i = e[i].ne)
		{
			int v = e[i].v;
			if (v == fa) continue;
			if (dep[v] >= mid - 1)
			{
				if (son) return tot -- , dfs(u, fa, mid);
				son = v;
			}
			else a[tot] = std :: max(a[tot], dep[v] + 1);
		}
		if (dep[u] == mid) return tot -- , dfs(u, fa, mid); 
		return find(son, u, mid);
	}
	int l[N + 5], r[N + 5];
	int que[N + 5], hh, tt;
	inline int get1(int l, int r)
	{
		while (hh <= tt && que[hh] < l) hh ++ ;
		for (int i = que[tt] + 1; i <= r; i ++ )
		{
			while (hh <= tt && a[i] + i > a[que[tt]] + que[tt]) tt -- ;
			que[ ++ tt] = i;
		}
		return a[que[hh]] + que[hh];
	}
	inline int get2(int l, int r)
	{
		while (hh <= tt && que[hh] > r) hh ++ ;
		for (int i = que[tt] - 1; i >= l; i -- )
		{
			while (hh <= tt && a[i] - i > a[que[tt]] - que[tt]) tt -- ;
			que[ ++ tt] = i;
		}
		return a[que[hh]] - que[hh];
	}
	inline bool check(int mid)
	{
		if (dep[root] <= mid) return 1;
		int son1 = 0, son2 = 0, max = 0;
		int _ = 0;
		for (int i = h[root]; ~i; i = e[i].ne)
		{
			int v = e[i].v;
			if (dep[v] >= mid - 1)
			{
				if (son1)
				{
					if (son2) return dfs(root, 0, mid) <= k;
					son2 = v;
				}
				else son1 = v;
			}
			else max = std :: max(max, dep[v] + 1);
		}
		tot = 0;
		int cnt = find(son1, root, mid);
		std :: reverse(a + 1, a + tot + 1);
		cnt += find(son2, root, mid), a[ ++ tot] = max;
		// printf("%d\n", cnt);
		// for (int i = 1; i <= tot; i ++ ) printf("%d ", a[i]);
		// puts("");
		if (cnt > k) return 0;
		if (tot == 1) return 1;
		hh = 1, tt = 0;
		que[tt] = 0;
		l[0] = 0;
		for (int i = 1; i <= tot; i ++ )
		{
			l[i] = l[i - 1];
			while (get1(l[i] + 1, i) > l[i] + mid) l[i] ++ ;
			// printf("%d ", l[i]);
		}
		// puts("");
		hh = 1, tt = 0;
		que[tt] = tot + 1;
		// printf("%d\n", get2(tot, tot));
		r[tot + 1] = tot + 1;
		for (int i = tot; i >= 1; i -- )
		{
			r[i] = r[i + 1];
			while (get2(i, r[i] - 1) > mid - r[i]) r[i] -- ;
			// printf("%d ", r[i]);
		}
		// puts("");
		int res = cnt + tot;
		for (int i = 1; i <= tot; i ++ ) res = std :: min(res, cnt + tot - 2 * std :: min(i - l[i], r[i + 1] - i - 1));
		return res <= k;
	}
	int main()
	{
		n = read(), k = read();
		for (int i = 1; i <= n; i ++ ) h[i] = -1; idx = 0;
		for (int i = 1; i < n; i ++ )
		{
			int u = read(), v = read();
			connect(u, v), connect(v, u);
		}
		if (k == n) return puts("0"), 0;
		init(1, 0);
		int s = 1;
		for (int i = 1; i <= n; i ++ ) if (dis[s] < dis[i]) s = i;
		init(s, 0);
		int t = 1;
		for (int i = 1; i <= n; i ++ ) if (dis[t] < dis[i]) t = i;
		rnw = 0;
		find_path(s, 0, t);
		root = path[rnw + 1 >> 1];
		init(root, 0);
		int l = 1, r = rnw - 1 >> 1;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (check(mid)) r = mid - 1;
			else l = mid + 1;
		}
		// printf("%d\n", check(6));
		printf("%d\n", l);
		// for (int i = 1; i < n; i ++ ) if (!check(i + 1) && check(i)) fprintf(stderr, "%d fuck\n", i);
		return 0;
	}
}
int main()
{
#ifdef LOCAL
	// freopen("in.txt", "r", stdin);
	// freopen("hub3.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
#endif
	read(); int T = read();
	while (T -- ) MYJBCHX :: main();
	fprintf(stderr, "%.2lfs\n", std :: clock() / 1000.0);
	return 0;
}