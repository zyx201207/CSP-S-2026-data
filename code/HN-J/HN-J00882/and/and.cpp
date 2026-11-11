#include <iostream>
#include <cstdio>
using namespace std;

constexpr int MAXN = 2e5 + 10;
constexpr int K = 35;

int n, m, a[MAXN], ans;
bool is[K][MAXN];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (register int i = 1; i <= n; ++i) cin >> a[i];
	for (register int i = 1; i <= n; ++i) for (register int j = 0; j < 30; ++j) if (a[i] & (1 << j)) is[j][i] = true;
	
	for (register int i = 29; ~i; --i) {
		int cnt = 0;
		for (register int j = 1; j <= n; ++j) cnt += is[i][j];
		if (cnt >= m) {
			ans += 1 << i;
			for (register int j = i - 1; ~j; --j) for (register int k = 1; k <= n; ++k) if (is[j][k] && !is[i][k]) is[j][k] = false;
		} 
	}
	
	cout << ans;
	return 0;
}
