#include <bits/stdc++.h>
#define ll long long 
#define mkp make_pair
using namespace std;
const ll N = 2e6 + 10, M = 5e3 + 10;
ll read(ll x = 0, ll f = 1) {
	char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') {
		f *= -1, c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
void write(ll x) {
	string s = to_string(x);
	for (int i = 0; i < int(s.size()); i++) putchar(s[i]);
	putchar('\n');
	return;
}
ll n, d, x[N], ans;
ll dis[301][301], vis[301][301];
void dfs(ll u, ll p, ll w) {
	if (w < dis[u][p]) dis[u][p] = w, vis[u][p] = 1;
	else if (w == dis[u][p]) vis[u][p]++;
	for (int i = p + 1; i <= n; i++) {
		if (x[i] - x[p] <= d) {
			dfs(u, i, w + 1);
		}else return;
	}
	return;
}
void solve() {
	ans = 0;
	n = read(), d = read();
	for (int i = 1; i <= n; i++) {
		x[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dis[i][j] = 1e18, vis[i][j] = 0;
		dfs(i, i, 0);
		for (int j = i + 1; j <= n; j++) ans += (vis[i][j] * (vis[i][j] - 1) / 2);
	}
	write(ans);
	return;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll t = 1, c = 0;
	c = read(), t = read();
	while (t--) solve();
	return 0;
}
