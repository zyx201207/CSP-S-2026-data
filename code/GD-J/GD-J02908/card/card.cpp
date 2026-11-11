#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
const int M = 3e5 + 10;
bool vis[M]; 
int ans[M]; 
int c[N], las[M]; 
int nxt[N];
vector<int> g[N];

int dfs(int u, set<int>& s) {
	bool flag = true;
	if (s.count(c[u])) flag = false;
	if (flag) s.insert(c[u]);
	int tmp = 1;
	for (int v : g[u])
		tmp += dfs(v, s);
	if (flag) s.erase(c[u]), ans[c[u]] += tmp;
	return tmp;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++) 
		las[c[i]] = i;
	for (int i = n; i >= 1; i--) {
		if (las[c[i]] > i) g[las[c[i]] + 1].push_back(i), nxt[i] = las[c[i]] + 1;
		else g[i + 1].push_back(i), nxt[i] = i + 1;
	} set<int> s;
	for (int i = n; i >= 1; i--)
		if (nxt[i] == n + 1) 
			dfs(i, s);
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0; 
}
