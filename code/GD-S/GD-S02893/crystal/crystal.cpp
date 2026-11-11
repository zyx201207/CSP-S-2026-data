#include <bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
} 
const int N = 5e5 + 5;
int n, a[N], m, s[N], ans;
signed main() {
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	n = rd, m = rd;
	for (int i = 1; i <= n; ++i) a[i] = rd;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for (int i = 1, j = 1; i <= n; ++i) {
		while (a[i] * (i - j + 1) - (s[i] - s[j - 1]) > m) ++j;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
