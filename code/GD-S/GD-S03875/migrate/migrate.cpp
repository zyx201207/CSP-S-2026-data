#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e6+3;
bool vis[N];
int n, mn, cnt;
LL x[N], d;

void dfs(int u, int tar, int dis) {
	if(u == tar) {
		if(dis < mn) {
			mn = dis;
			cnt = 1;
		} else if(dis == mn)
			++cnt;
		return;
	}
	if(x[tar] < x[u]) {
		for(int v = u-1; v && x[u]-x[v] <= d; --v)
			if(!vis[v]) {
				vis[v] = true;
				dfs(v, tar, dis+1);
				vis[v] = false;
			}
	} else
		for(int v = u+1; v <= n && x[v]-x[u] <= d; ++v)
			if(!vis[v]) {
				vis[v] = true;
				dfs(v, tar, dis+1);
				vis[v] = false;
			}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T >> _T;
	for(; _T--; cout.put('\n')) {
		cin >> n >> d;
		for(int i = 1; i <= n; ++i)
			cin >> x[i];
		LL ans = 0;
		for(int u = 1; u < n; ++u)
			for(int v = u+1; v <= n; ++v) {
				mn = n+1; cnt = 0;
				vis[u] = true;
				dfs(u, v, 0);
				vis[u] = false;
				if(cnt == 2)
					++ans;
			}
		cout << ans;
	}
	cout.flush(); return 0;
}