//From: CSP-S
//Problem: T4研发基地（hub） 
//文件名: hub.in/.out/.cpp
//时间限制: 3000 ms
//空间限制: 1024 MiB 
//预期得分: 15 pts 
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 10;
constexpr int N1 = 300 + 10;
constexpr int INF = 1e9 + 10;

int c, T;
int n, k;
vector <int> g[N];
int f[N][21], deep[N];//u 节点跳 2^j 步到的节点为 f[u][j] 
vector <int> s;
bool vis[N1];
bool ok[N1];
int ans = INF;

void dfs(int u, int fa) {
	deep[u] = deep[fa] + 1;
	f[u][0] = fa;
	for (int i = 1; i <= 20; i ++) f[u][i] = f[f[u][i - 1]][i - 1];
	for (int v : g[u]) {
//		cout << "(" << u << ", " << v << ")\n";
		if (v == fa) continue;
		dfs(v, u);
	}
}

int lca(int x, int y) {//求 x,y 的最近公共祖先 
	if (deep[x] > deep[y]) swap(x, y);//层数小的在上面
	for (int i = 20; i >= 0; i --) {//跳至同一层 
		if (deep[f[y][i]] >= deep[x]) y = f[y][i];
	}
	if (x == y) return x;//本来就在一起了，直接 return 即可 
	for (int i = 20; i >= 0; i --) {//一直往上跳 
		if (f[y][i] != f[x][i]) y = f[y][i], x = f[x][i];
	}
	return f[x][0];//返回 x 的父亲节点 
}

int dist(int u, int v) {//求任意两点间的距离
	return deep[u] /*u 的深度*/ + deep[v] /*v 的深度*/ - 2 * deep[lca(u, v)] /*它们 lca 的深度*/;
}

void init() {//多测记得初始化
	for (int i = 1; i <= n; i ++) g[i].clear();
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= 20; j ++) f[i][j] = 0;
		deep[i] = 0;
	}
	ans = INF;
}

void check(int u, int fa) {//检查连通块
	ok[u] = true; 
//	cout << u << " " << fa << endl;
	for (int v : g[u]) {
		if (v == fa) continue;
		if (!vis[v]) continue;//不在集合中 
		check(v, u);
	}
}

void choose(int dep) {//遍历多少个了，选取的集合（大小就是选择的个数） 
//	cout << dep << ": ";
//	for (int v : s) cout << v << " ";
//	cout << endl;
	if (n - dep + 1 < k - int(s.size())) return;
	if ((int)s.size() == k) {//size 要转为 int 
//		for (int i : s) cout << i << " ";
//		cout << endl;
		//选取完成
		for (int i = 1; i <= n; i ++) ok[i] = false;
		int cnt = 0;
		for (int v : s) {
			if (!ok[v]) {
				check(v, 0);
				cnt ++;
			}
//			for (int i = 1; i <= n; i ++) cout << ok[i] << " ";
//			cout << "\n"; 
		}
		if (cnt > 2) return;//连通块>2，不合法 
		int sum = 0;
		for (int i = 1; i <= n; i ++) {
			int tmp = INF;
			if (vis[i]) continue;//属于这个集合，d(i)=0; 
			for (int v : s) tmp = min(dist(v, i), tmp);
			sum = max(sum, tmp);
		}
//		cout << "和为 " << sum << "\n";
		ans = min(sum, ans);
		return;
	}
	if (dep >= n + 1) return;
	s.push_back(dep);
	vis[dep] = true;
	choose(dep + 1);
	s.pop_back();
	vis[dep] = false;
	choose(dep + 1);
}

void solve1() {
	init();
	cin >> n >> k;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	deep[0] = 0;
	dfs(1, 0);
//	cout << ans << "\n";
	choose(1);
	cout << ans << "\n";
//	cout << dist(1, 2) << ", " << dist(3, 4) << "\n";
//	for (int i = 1; i <= n; i ++) cout << deep[i] << " ";
//	cout << "\n";
}

void solve2() {
	init();
	cin >> n >> k;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int m = (n - 1) / 2 + 1;
	cout << max(m - k, 0) << "\n"; 
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	if (c >= 13 && c <= 14) {
		while (T --) solve2();
	}else {
		while (T --) solve1();
	}
	return 0;
}
