#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e6 + 5;
ll x[N];
bool vis[N];
ll ans;
ll n, d;

ll can (ll l, ll r) {
	memset(vis, 0, sizeof(vis));
	vector<int> step;
	step.push_back(l);

	for (int i = 0; step.size(); i++) {
		vector<int> nxt;
		int cnt = 0;
		for (int j = 0; j < step.size(); j++) {
			for (int k = 1; step[j] + k <= r && x[step[j] + k] - x[step[j]] <= d; k++) {
				int idx = step[j] + k;
				if (vis[idx]) continue;
				if (idx != r) vis[idx] = true;
				nxt.push_back(idx);
				if (idx == r) cnt++;
			}
		}
		if (cnt == 2) return true;
		step.swap(nxt);
	}
	return false;
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];

		ans = 0;
		for (int i = 1; i <= n; i++) for (int j = i + 2; j <= n; j++) if (can(i, j)) ans++;
		cout << ans << "\n";
	}
	return 0;
}

