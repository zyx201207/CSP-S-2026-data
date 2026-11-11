#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAXN = 2e5 + 5;
ll n, m, a[MAXN], ans = 0, maxn;

inline void dfs(ll step, ll val, ll st) {
	if (step == m + 1) {
		ans = max(ans, val);
		return;
	}
	maxn = 0;
	for (ll i = st; i <= n; i++) {
		maxn = max(maxn, val & a[i]);
	}
	if (maxn < ans) return;
	for (ll i = st; i <= n; i++) {
		dfs(step + 1, val & a[i], i + 1);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	if (m != n) {
		dfs(1, (1ll << 31) - 1, 1);
	} else {
		ans = a[1];
		for (ll i = 2; i <= n; i++) {
			ans = ans & a[i];
		}
	}
	
	cout << ans << endl;
	return 0;
}

