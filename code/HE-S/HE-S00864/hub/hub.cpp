#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int v, T, n, k, sum, ans, mid, a[N];
vector<int> G[N];
void fun (int x, int fa, int cnt, bool r) {
//x:结点编号  cnt:便利的长度 r:1从跟循环下来，0从叶子节点循环下来 
	if (mid == cnt) {
		if (r == 0) sum ++, fun(x, fa, 0, 1); 
		else fun(x, fa, 0, 0);
		return;
	}
	if (G[x].size() < mid && sum == 0) sum ++; 
	for (auto i : G[x]) {
		if (i != fa) fun(i, x, cnt + 1, r);
	}
	return;
}
bool check(int x) {
	for (int i = 1; i <= n; i ++)
		if (a[i] == 1) {
			fun(i, 0, 0, 0); break;
		} 
	return sum <= k;
}
void solve() {
	cin >> n >> k;
	for (int i = 0; i <= n; i ++) G[i].clear();
	for (int i = 1; i < n; i ++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		a[u] ++, a[v] ++;
	}
	int l = 1, r = n;
	while (l < r) {
		sum = 0;
		mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans / 2 + 1 << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> T;
	while (T --) {
		solve();
	}
	return 0;
}
