#include <bits/stdc++.h>
#define ll long long 
using namespace std;
constexpr int N = 2e6 + 5;
int n;
ll d, x[N];
namespace subtask1{
	ll sum, sam;
	void dfs(int t, int tg, int tot) {
		if (t == tg) {
			if (tot < sum) {
				sam = 1;
				sum = tot;
			} else if (tot == sum) ++sam;
			return;
		}
		for (int i = t + 1; i <= tg; ++i) {
			if (x[i] - x[t] <= d) {
				dfs(i, tg, tot + 1);
			} else break;
		}
	}
	void solve() {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				sum = 2e18;
				dfs(i, j, 0);
				if (sam == 2 && sum != 2e18) ++ans;
			}
		}
		cout << ans << '\n';
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		if (c <= 2) subtask1::solve();
		else if (x[n] - x[1] <= d) cout << "0\n";
	}
	return 0;
}

// start on 17:00; complete on 17:30; check on 18:23
