#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

using ll = long long;

void init() {}

int n, k, head[N], dep[N];
struct
{
	int v, next;
} e[N << 1];

void add(int u, int v)
{
	static int cnt = 0;
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}

namespace brute_force
{
	const ll N1 = 100;

	ll f[N1][N1][N1][2], g[N1];

	void dfs(int u, int fa)
	{
		dep[u] = dep[fa] + 1;
		for (int i = head[u], v; i; i = e[i].next)
		{
			if ((v = e[i].v) == fa)
				continue;
		}
	}

	void solve1()
	{
		cin >> n >> k;
		for (int i = 1, u, v; i <= n; ++i)
		{
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
	}
}

void solve()
{
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	// freopen("hub.err", "w", stderr);
	int _ = 1, __;
	cin >> __ >> _;
	init();
	while (_--)
	{
		if (__ <= 6)
			brute_force::solve1();
		else
			solve();
	}
	return 0;
}
/*
g++ hub.cpp -o hub.exe -std=c++14 -O2
*/
/*
n^3 推完了
g_u = max dep
f_{u, d, k, 1/2}
d 是最低连通块深度，k 是不在连通块的子树内的 max dep
不想写 XD
回去让 gpt 教我吧
唉，写一点吧
不对啊
这是 n^4
还要记录已经选了几个点
我能成功击败 n^4 吗（
啊啊啊啊啊啊啊
真的不会写这个啊
投降喵（
*/