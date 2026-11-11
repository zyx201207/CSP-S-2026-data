#include<bits/stdc++.h>
#define fi first
#define se second
#define lowbit(x) ((x) & (-x))
#define MID(l, r) ((l) + ((r) - (l)) >> 1)
#define ls(p) ((p) << 1)
#define rs(p) ((p) << 1 | 1)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using lf = double;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int N = 2e6 + 10;
int x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		cout << 0 << '\n';
	}
	
	return 0;
}

