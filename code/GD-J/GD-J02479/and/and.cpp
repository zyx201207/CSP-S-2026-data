#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, a[N], ans;
bool vis[N];

void dfs(int pos, int x, int sum) {
	if(pos >= m) {
		ans = max(ans, sum);
		return;
	}
	vis[x] = true;
	for(int i = 1;i <= n;i++) {
		if(!vis[i]) dfs(pos + 1, i, sum & a[i]);
	}
	vis[x] = false;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) dfs(1, i, a[i]);
	cout << ans;
	return 0;
}
