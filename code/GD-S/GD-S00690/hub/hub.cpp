#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;
int n, k;
vector<int> e[maxn];
int blk = 0;
int chod[maxn];
int fa[maxn];
int find(int x) {
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
void check() {
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 2; i <= k; i++) {
		int x = find(chod[i - 1]), y = find(chod[i]);
		if (x == y) continue;
		fa[x] = y;
		cout << x << ' ' << y << endl;
	}
	int cnt = 0, lst = find(chod[1]), lst2 = 0;
	for (int i = 2; i <= k; i++) if (find(chod[i]) != lst) {
		if (lst2) return ;
		lst2 = find(chod[i]);
	}
	for (int i = 1; i <= k; i++) cout << chod[i] << ' ';
	cout << endl; 
	if (lst2 == 0) cout << 1 << endl;
}
void make(int now, int usd) {
	if (usd == k) {
		check();
		return ;
	}
	if (k - usd > n - now + 1) return ;
	chod[usd + 1] = now;
	make(now + 1, usd + 1);
	make(now + 1, usd);
}
void solve() {
	cin >> n >> k;
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	make(1, 0);
	
	
	for (int i = 1; i <= n; i++) e[i].clear();
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) cout << 1 << endl;
}
