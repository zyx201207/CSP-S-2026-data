#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int test, t;
const int MAXN = 2000005;
LL x[MAXN];
LL n, d;
LL dis[MAXN];
LL cnt[MAXN];

void dfs(int u, int fa, LL step) {
	if (dis[u] == step) {
		cnt[u] += cnt[u] + 1;
	} if (dis[u] > step) {
		dis[u] = step;
		cnt[u] = 0;
	}
	
	for (int i = u + 1; i <= n; i++) {
		if (x[i] - x[u] <= d) {
			dfs(i, u, step + 1);
		} else {
			break;
		}
	}
	return ;
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		dis[i] = 2e18;
		cin >> x[i];
	} 
	
	dfs(1, 0, 0);
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += cnt[i];
	} cout << ans << endl;
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> test >> t;
	while (t--) {
		solve();
	}

	return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/

