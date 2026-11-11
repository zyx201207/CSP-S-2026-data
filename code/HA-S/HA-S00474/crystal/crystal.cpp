#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 5;
ll a[N];
ll b[N];

ll n, m;
ll ans;

bool check (ll s) {
	ll mid = s >> 1;
	ll been_c = 0;
	for (int i = 1; i <= s; i++) {
		been_c += abs(a[i] - a[mid]);
		if (been_c > m) return false;
	}
	return true;
}

void dfs (ll last, ll idx) {
	if (idx > m) return ;
	if (check(idx)) ans = max(ans, idx);
	else if (last + 1 <= n && a[last + 1] != a[last]) return ;
	for (int i = last + 1; i <= n; i++) {
		b[idx + 1] = a[i];
		dfs(i, idx + 1);
	}
}

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];

	dfs(0, 0);

	cout << ans << "\n";
	return 0;
}

