#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using cint = const int;
using cLL = const long long;
using uint = unsigned int;
using uLL = unsigned long long;

#define N 2000005
#define base 137
#define inf 1000000007
#define mod 998244353

const double PI = acos(-1.0);

int n;
LL d;
LL x[N];

int far[N];
LL ans = 0ll;

int ed;
int b, c;
void dfs(cint p, cint cnt) {
	if (p == ed) {
		if (cnt < b) b = cnt, c = 1;
		else if (cnt == b) ++c;
		return;
	}
	for (int i = p + 1; i <= min(ed, far[p]); ++i)
		dfs(i, cnt + 1);
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (; t--; ) {
		ans = 0ll;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
			cin >> x[i];
		for (int i = 1; i <= n; ++i) {
			int l = i, r = n + 1;
			for (int mid; l + 1 < r; ) {
				mid = l + r >> 1;
				if (x[mid] - x[i] <= d)
					l = mid;
				else
					r = mid;
			}
			far[i] = l;
		}
		if (c <= 2) {
			for (int i = 1; i < n; ++i)
				for (int j = i + 1; j <= n; ++j) {
					ed = j;
					b = inf, c = 1;
					dfs(i, 0);
					if (c == 2)
						++ans;
				}
		}
		else if (c <= 6) {
			for (int i = 1; i < n; ++i) {
				bool g = true;
				for (int j = i + 1; j <= n; ++j) {
					int cnt = 0;
					for (int k = i; k <= j; k = far[k]) {
						++cnt;
						if (k == far[k] && k < j) {
							g = false;
							break;
						}
					}
					if (!g) break;
					;
				}
			}
		}
		else {
			;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
