#include <bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
const int N = 5e5 + 5;
int n, m, a[N], r[N], ans[N], b[N], d[N], f[N];
vector<int> g[N];
queue<int> q;
signed main() {
	freopen("card.in", "r", stdin), freopen("card.out", "w", stdout);
	n = rd, m = rd;
	for (int i = 1; i <= n; ++i) a[i] = rd;
	for (int i = n; i >= 1; --i) {
		if (!r[a[i]]) r[a[i]] = i;
		else b[i] = 1;
	}
	for (int i = 1; i < n; ++i)
		if (!b[i]) {
			if (b[i + 1]) g[i].push_back(r[a[i + 1]]), ++d[r[a[i + 1]]];
			else g[i].push_back(i + 1), ++d[i + 1];
		}
	for (int i = 1; i <= n; ++i) 
		if (!b[i]) {
			if (!d[i]) q.push(i);
			f[i]++;
		} else f[r[a[i]]]++;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			f[v] += f[u];
			if (!--d[v]) q.push(v);
		}
	}
	for (int i = 1; i <= n; ++i) if (!b[i]) ans[a[i]] = f[i];
	for (int i = 1; i <= m; ++i) cout << ans[i] << ' '; 
	return 0;
}
