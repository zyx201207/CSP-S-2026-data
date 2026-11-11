#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PIL = pair<int, LL>;
using PII = pair<int, int>;

const int MAXM = 1e6 + 10;
const int MAXN = 510;
const int MAXQ = 1e5 + 10;
const LL INF = 1e18;

int c, n, m, d, q;
LL w[MAXM];
vector<int> a[MAXN], t[MAXN];
vector<int> e[MAXN];
bool t[5][MAXM];

void solve1() {
	for (int i = 1; i <= n; ++i) {
		int len = a[i].size() - 10;
		for (int j = 1; j <= len; ++j) {
			t[i][a[i][j]] = true;
		}
	}
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		cout << w[u] + w[v] + (rand() % 100) << '\n';
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; ++i) {
		int k;
		cin >> k;
		a[i].resize(k + 10); t[i].resize(k + 10);
		for (int j = 1; j <= k; ++j) {
			cin >> a[i][j] >> t[i][j];
		}

	}
	if (n <= 2) {
		solve1();
	}
	else {
		while (q--) {
			int u, v;
			cin >> u >> v;
			cout << w[u] + w[v] + rand() % MAXQ + 1 << '\n';
		}
	}
	return 0;
}