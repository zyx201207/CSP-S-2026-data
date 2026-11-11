#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
typedef pair<int, int> PII;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 310;
int c, T, n, d, x[N], r[N];

void solve() {
	n = read(), d = read();
	for (int i = 1; i <= n; i ++) x[i] = read();
	for (int i = 1, j = 1; i <= n; i ++) {
		while (j <= n && x[j] - x[i] <= d) j ++;
		r[i] = j - 1;
	}
	int res = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			vector<int> vec; 
			int x = i, flag = 1;
			while (true) {
				vec.push_back(x); 
				if (x == r[x]) {
					flag = 0; break;
				}
				x = r[x];
				if (x >= j) break;
			}
			if (!flag) continue;
			vector<PII> v;
			for (auto x : vec) {
				int t = x;
				while (r[t] == r[x]) t --; 
				t ++; 
				v.push_back({t, r[t]});  
			}
			int S = 0;
			for (int i = 1; i < (int)v.size(); i ++) S += max(0ll, v[i - 1].second - v[i].first);
			if (S == 1) res ++; 
		}
	printf("%lld\n", res);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), T = read();
	while (T --) solve();
	return 0;
}
