#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 15;

int n, k;
vector <int> linker[N];

int cho[N], cnt;
bool vis[N];

int fa[N];
int find(int x) { return (fa[x] == x ? x : (fa[x] = find(fa[x]))); }

void ToSee(int x, int father) {
	for (int v : linker[x]) {
		if (v == father) continue;
		if (vis[v] && vis[x])
			fa[find(v)] = find(x);
		ToSee(v, x);
	}
}

bool check() {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	
	ToSee(1, 0);
	
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] && fa[i] == i)
			tot++;
	}
	
	return tot <= 2;
}

int dis[N];

int Go(int x, int father) {
	int res = 0;
	for (int v : linker[x]) {
		if (v == father) continue;
		dis[v] = dis[x] + 1;
		Go(v, x);
	}
	return res;
}

int ans = 1e9;
void DFS(int now) {
	if (now == k + 1) {
		if (!check()) return ;
		
//		for (int i = 1; i <= cnt; i++)
//			cout << cho[i] << " ";
		
		int res = 0;
		for (int i = 1; i <= cnt; i++) {
			memset(dis, 0, sizeof(dis));
			Go(cho[i], 0);
			for (int j = 1; j <= cnt; j++) {
//				cout << dis[cho[j]] << " ";
				if (cho[i] != cho[j]) res = max(res, dis[cho[j]]);
			}
		}
		
//		cout << res << "!!!!!!!!!!!\n";
		
		ans = min(ans, res);
	}
	
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		if (i < cho[cnt]) continue;
		vis[i] = 1, cho[++cnt] = i;
		DFS(now + 1);
		vis[i] = 0, cho[cnt--] = 0;
	}
}

void solve(int C) {
	cin >> n >> k;
	
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		linker[u].push_back(v);
		linker[v].push_back(u);
	}
	
	ans = 1e9, DFS(1);
	
	cout << ans << endl;
	
	for (int i = 1; i <= n; i++)
		linker[i].clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int C, T; cin >> C >> T;
	while (T--) solve(C);
	
	return 0;
}
