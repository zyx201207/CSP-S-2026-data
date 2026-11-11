#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500005;
const int M = 300005;
int n, m, cnt, a[N], q[N], b[M], v[M], f[M];

void solve() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		cnt = 0;
		memset(v, 0, sizeof(v));
		for (int j = i; j <= n; ++j) {
			if (v[a[j]]) {
				for (int k = v[a[j]] + 1; k <= cnt; ++k) {
					v[q[k]] = false;
				}
				cnt = v[a[j]];
			} else {
				q[++cnt] = a[j];
				v[a[j]] = cnt;
			}
		}
		
		for (int j = 1; j <= cnt; ++j) {
			++f[q[j]];
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		cout << f[i] << ' ';
	}
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}
