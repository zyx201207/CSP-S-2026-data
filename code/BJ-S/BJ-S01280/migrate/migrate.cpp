#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
inline long long read(){
	long long x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
	return x * f;
}

inline void write(long long x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else write(x / 10), putchar((x % 10) + 48);
}

long long c, t, n, d, a[2000006], nxt[2000006], pre[2000006], nxtd[2000006], pred[2000006];
long long ans;
void solve(){
	n = read(), d = read();
	ans = 0;
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) nxt[i] = upper_bound(a + i, a + n + 1, a[i] + d) - a - 1;
	for (int i = n; i >= 1; i--) nxtd[i] = nxt[i] - nxt[i - 1];
	for (int i = n; i >= 1; i--) if (nxtd[i] != 0) nxtd[i] += nxtd[nxt[i]];
	for (int i = 1; i <= n; i++) pre[i] = lower_bound(a + 1, a + i + 1, a[i] - d) - a;
	for (int i = 1; i <= n; i++) pred[i] = pre[i + 1] - pre[i];
	for (int i = 1; i <= n; i++) if (pred[i] != 0) pred[i] += pred[pre[i]];
	
	for (int i = 1; i <= n - 3; i++) {
		if (nxt[i] <= nxt[i - 1] || nxt[i] <= i + 1) continue;
		int j = nxt[i];
		if (nxt[j - 1] <= nxt[j - 2] || nxt[j - 1] <= j) continue;
		long long res = 1;
		if (nxt[j] == nxt[j - 1]) res *= (nxtd[j - 1]);
		if (pre[j] == pre[j - 1]) res *= (pred[i] + 1);
		ans += res;
		
	}
	cout << ans << "\n";
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while (t--) solve();
	return 0;
}