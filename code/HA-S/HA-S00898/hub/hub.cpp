#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> es(n + 5);
	vector<int> pred(n + 5);
	vector<pair<int, int>> te;
	te.reserve(n - 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		es[x].push_back(y); es[y].push_back(x);
		pred[x]++, pred[y]++;
		te.push_back(make_pair(x, y));
	}
	if (k >= n) {
		cout << 0 << '\n';
		return;
	}
	int ans = n;
	vector<int> col(n + 5);
	function<int(int, int, int)> calc = [&](int u, int fa, int c) {
		int res = 1;
		col[u] = c;
		for (auto& v : es[u]) {
			if (v == fa) continue;
			res += calc(v, u, c);
		}
		return res;
	};
	random_shuffle(te.begin(), te.end());
	for (auto tmp : te) {
		vector<int> d(pred);
		int x = tmp.first, y = tmp.second;
		--d[x];
		--d[y];
		int sumx = calc(x, y, x), sumy = calc(y, x, y);
		int res = 0;
		stack<int> s;
		for (int i = 1; i <= n; i++) if (d[i] == 1) s.push(i);
		while ((sumx == 0 ? 1 : sumx) + (sumy == 0 ? 1 : sumy) > k) {
			res++;
			if (res >= ans) break;
			stack<int> ns;
			while (s.size()) {
				int u = s.top(); s.pop();
				if (col[u] == col[x]) sumx--;
				else sumy--;
				for (auto& v : es[u]) {
					if ((u == y && v == x) || (u == x && v == y)) continue;
					if (--d[v] == 1) ns.push(v);
				}
			}
			swap(s, ns);
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
