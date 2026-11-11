#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e6 + 5;

int n, k, dis[N], max[N], F[N], ans;
std::vector<int> e[N], g[N];

void dfs(int u, int fa, int &res) {
//	printf("#%d %d\n", u, fa);
	dis[u] = dis[fa] + 1; F[u] = fa; max[u] = 0;
	if (dis[u] > dis[res]) res = u;
	for (int v : g[u])
		if (v ^ fa)
			dfs(v, u, res), max[u] = std::max(max[u], 1 + max[v]);
}

std::priority_queue<std::pair<int, int>> que;

void set(int u) {
	for (int v : g[u])
		if (v != F[u])
			que.push({max[v] + 1, v});
}

std::vector<int> calc(int rt) {
//	puts(">");
	int a = rt; dfs(rt, 0, a);
//	printf("%d\n", a);
	int b = a; dfs(a, 0, b);
	int root = b;
	for (int i = 1; i <= dis[b] >> 1; ++i)
		root = F[root];
	dfs(root, 0, rt);
	std::vector<int> ans; ans.push_back(0);
	while (!que.empty()) que.pop(); 
	set(root);
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		int cur = p.first, u = p.second;
		ans.push_back(cur);
		set(u);
	} ans.push_back(0);
	return ans;
}

void ck(int a, int b) {
//	printf(">%d %d\n", a, b);
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 1; i <= n; ++i) 
		for (int j : e[i]) {
			if (i == a && j == b || i == b && j == a) continue;
			g[i].push_back(j); 
		}
	auto A = calc(a);
//	puts("!");
	auto B = calc(b);
//	for (int x : A) printf("!%d ", x); puts("");
//	for (int x : B) printf("!%d ", x); puts("");
	for (int i = 1; i < k; ++i) {
		if (i < A.size() && k - i < B.size())
		ans = std::min(ans, std::max(A[i], B[k - i]));
	}
}


void run()
{
	scanf("%d%d", &n, &k); ans = 1e6;
//	printf(">%d %d\n", n, k);
	for (int i = 1; i <= n; ++i) e[i].clear();
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		for (int j : e[i]) 
			ck(i, j);
	printf("%d\n", ans);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T; scanf("%d%d", &c, &T);
	while (T--) run();
	return 0;
}
