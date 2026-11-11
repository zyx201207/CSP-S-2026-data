#include <iostream>
#include <cctype>
#define gc getchar
#define pc putchar
#define int long long
using namespace std;
const int N = 200005, M = 33;
int n, m, a[N], now, ans;
bool f[N][M], ban[N];
inline void rd(int &x) {
	int sum = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
	for (; isdigit(c); c = gc()) sum = sum * 10 + c - '0';
	x = sum * f;
}
inline void wt(int x) {
	if (x > 9) wt(x/10);
	pc(x%10+'0');
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	rd(n); rd(m);
	for (int i = 1; i <= n; i++) {
		rd(a[i]);
		for (int j = 0; j <= 30; j++) {
			if (a[i] & (1 << j)) f[i][j+1] = 1;
		}
	}
	for (int i = 31; i; i--) {
		now = 0;
		for (int j = 1; j <= n; j++) {
			if (ban[j]) continue;
			now += f[j][i];
		}
		if (now >= m) {
			ans += (1 << (i-1));
			for (int j = 1; j <= n; j++) {
				if (!f[j][i]) ban[j] = 1;
			}
		}
	}
	wt(ans);
	return 0;
}
