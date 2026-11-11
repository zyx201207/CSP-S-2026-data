#include <bits/stdc++.h>

#define END exit(0);

using namespace std;
using LL = long long;

const int MAXN = 3010;

int n, len[MAXN], cnt, res[MAXN]; LL d, x[MAXN];
vector<int> e[MAXN];

void bfs(int s) {
	memset(len, 0, sizeof(len));
	memset(res, 0, sizeof(res));
	queue<int> q;
	q.push(s);
	len[s] = 1; res[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (len[v] == len[u] + 1)
				res[v] += res[u];
			if (!len[v]) {
				len[v] = len[u] + 1;
				res[v] = res[u];
				q.push(v);
			} 
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (i != s && res[i] == 2) 
			++cnt; 
	}
}

void solveB() {
	LL p = n;
	LL tot = (p - 1) * (p - 2) / 2;
	cout << tot << '\n';
}

void solveA(int t) {
	while (t--) {

	}
}

void solve() {
	cin >> n >> d; cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		e[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (labs(x[i] - x[j]) <= d) {
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	} 
	for (int i = 1; i <= n; ++i) {
		if (e[i].size() == (n - 1)) {
			solveB();
			return ;
		}
	}
	for (int i = 1; i <= n; ++i) {
		bfs(i);
	}
	cout << (cnt / 2) << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	if (c == 11 || c == 12) {
		solveA(t);
	}
	while (t--) {
		solve();
	}
	return 0;
}