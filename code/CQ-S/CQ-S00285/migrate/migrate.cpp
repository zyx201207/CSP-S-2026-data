/*
等等，别告诉我是线段树优化建图，有这个考点吗？
15:56 先打暴力了 
16:01 发现建反图可以优化为 n^2 
16:16 假了, 打n^3 
16:30 24pts到手
16:50 +8

*/

#include <bits/stdc++.h>
//#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 303;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int test = 1, tt = 1;
int C; 
int n, dis[N][N];
long long x[N], d;
vector<vector<int>> e;
int in[N];
int cnt[N];
int s[N];//并查集 
vector<pii> st;
int find(int x) {
	if (x == s[x]) return x;
	return s[x] = find(s[x]);
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
			}
		}
	}
}
queue<int> q;
void topu(int s) {
	q.push(s);
	cnt[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : e[u]) {
			if (dis[s][v] == dis[s][u] + 1) {
				cnt[v] += cnt[u];
			}
			if (!--in[v]) {
				q.push(v);
			}
		}
	}
}

void solve() {
	cin >> n >> d;
	e.assign(n + 2, vector<int>()); 
	st.clear();
	for (int i = 1; i <= n; i++) {
		in[i] = 0;
		cnt[i] = 0;
		s[i] = i;
		for (int j = 1; j <= n; j++) {
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (x[j] - x[i] <= d) {
				e[i].push_back(j);
				s[find(j)] = find(i);
				dis[i][j] = 1;
				in[j]++;
			} else {
				break;
			}
		}
	}
	floyd();//计算 dis 
	int pos = 1;
	for (int i = 2; i <= n; i++) {
		if (find(i) != find(i - 1)) {
			st.emplace_back(pos, i - 1);
			pos = i;
		}
	}
	st.emplace_back(pos, n);
	int ans = 0;
	for (auto o : st) {
		int l = o.fi, r = o.se;
		for (int i = l; i < r; i++) {
			//计算区间 i 到 r 
			for (int j = i; j <= r; j++) in[j] = cnt[j] = 0;
			for (int j = i; j <= r; j++) {
				for (auto v : e[j]) in[v]++;
			}
			topu(i);
			for (int j = i; j <= r; j++) {
				if (cnt[j] == 2) {
					ans++;
				}
			}
		}
	}
	cout << ans << '\n';
}

void solve_11_to_12() {
	cin >> n >> d;
	vector<long long> x(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	if (n == 1) {
		cout << "0\n";
		return;
	}
	long long dis = x[n] - x[n - 1];
	long long val = d / dis;
	if (val <= 1) {
		cout << "0\n";
		return;
	}
	cout << max(0ll, n - (2 * val - 1)) << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C;
	cin >> test;
	for (; tt <= test; tt++) {
		if (C == 11 || C == 12) {
			solve_11_to_12();
			continue;
		}
		solve();
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

