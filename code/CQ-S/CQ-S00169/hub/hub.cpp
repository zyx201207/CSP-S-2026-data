/*The code is from koukilee(luogu@)*/
#include <bits/stdc++.h>

typedef long long i64; typedef int i32;

const i64 MAXN = 1010100, INF = 992010081220091007;

inline void read (i64 &x) {scanf ("%lld", &x);}
inline void print (i64 x) {printf ("%lld", x);}
inline void put (i64 x) {print (x); putchar ('\n');}

/*
	好累啊
	15 分可以白拿
	考虑是不是稍微有一点点性质可以打的
	算了，直接打吧 
	真力竭了，打不动了 15 分
	
	就这样吧，如果目前不挂分是245，也算是新高了，一年比一年高欸，其实很满足了。
	再看看还有没有什么能打的部分分吧。 
*/

i64 c, T, n, k, vis[MAXN], ans, s[MAXN], v[MAXN], kv[MAXN];
std::vector <i64> G[MAXN];

inline void init ()  {
	ans = INF;
	for (i32 i = 1; i <= n; i++)
		G[i].clear (), vis[i] = 0;
}

i64 find (i64 x)  {return x == s[x] ? x : s[x] = find (s[x]);}

inline i64 check ()  {
	for (i32 i = 1; i <= n; i++)
		s[i] = i, v[i] = 0;
	
	for (i32 i = 1; i <= n; i++) {
		if (!vis[i]) continue;
		for (auto j : G[i]) {
			if (!vis[j]) continue;
			s[find (i)] = find (j);
		}
	}
	
	i64 tot = 0;
	
	for (i32 i = 1; i <= n; i++) {
		if (vis[i])
			tot += !v[find (i)], v[find (i)] = 1;
	}
	
	return tot <= 2;
}

i64 dfs2 (i64 u) noexcept {
	if (vis[u]) return 0;
	
	i64 l = INF; kv[u] = 1;
	
	for (auto it : G[u])
		if (!kv[it]) 
			l = std::min (l, dfs2 (it) + 1);
	
	kv[u] = 0;
	
	return l;
}

void dfs (i64 step, i64 sa)  {
	if (step > n) {
		if (sa != k) return;
		
		if (!check ()) return;
		
		i64 sum = 0;
		for (i32 i = 1; i <= n; i++)
			if (!vis[i])
				sum = std::max (sum, dfs2 (i));
		
//		for (i32 i = 1; i <= n; i++)
//			print (vis[i]), putchar (' ');
//		put (sum);
		
		ans = std::min (ans, sum);
		return ;
	}
	
	dfs (step + 1, sa);
	
	vis[step] = 1; dfs (step + 1, sa + 1); vis[step] = 0;
}

int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	read (c), read (T);
	
	while (T--) {
		read (n), read (k); init ();
		
		for (i32 i = 1; i < n; i++) {
			i64 x, y; read (x), read (y);
			G[x].push_back (y), G[y].push_back (x); 
		}
		
		dfs (1, 0);
		
		put (ans);	
	}
	return 0;
}
