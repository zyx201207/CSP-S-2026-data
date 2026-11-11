#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6 + 10;
bool flag;
int n, cnt;
ll d, a[MAXN], minn;
ll Min (int s, int e) {
	ll p = a[s], res = 0;
	for (int i = s + 1; i <= e; ++ i) {
		if (i + 1 <= e && a[i + 1] - p > d) {
			if (a[i] - p > d) return 0LL;
			p = a[i], res ++;
		} else if (i == e && p != a[i]) p = a[i], res ++;
	}
	return res;
}
void dfs (int u, int step, int end) {
	if (u == end && step == minn) { cnt ++; return; }
	if (step >= minn) return;
	if (step + 1 == minn) {
		if (a[end] - a[u] <= d) dfs (end, step + 1, end);
		else return;
	}
	if (cnt > 2) { return; }
	for (int i = u + 1; i < end; ++ i) {
		dfs (i, step + 1, end);
		if (cnt > 2) { return; }
	}
}
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int c, T; cin >> c >> T;
	while (T --) {
		cin >> n >> d;
		ll ans = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		bool flag = false;
		for (int i = 2; i < n; ++ i) {
			if (a[i] - a[i - 1] != a[i + 1] - a[i]) flag = true;
		}
		if (n >= 300) {
			cout << 0 << "\n";
			continue;
		}
		for (int k = 2; k <= n; ++ k) {
			for (int i = 1; i + k - 1 <= n; ++ i) {
				int j = i + k - 1;
				minn = Min (i, j);
				if (minn == 0) continue;
				cnt = 0;
				dfs (i, 0, j);
				if (cnt == 2) ans ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
