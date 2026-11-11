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

long long n, m, a[500005], s[500005];
long long sum, ans;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	long long cur = 0;
	for (int i = 1; i <= n; i++) {
		while (1LL * (i - cur - 1) * a[i] - (s[i - 1] - s[cur]) > m) cur++;
		while (a[i] == a[i + 1] && i < n) i++;
		ans = max(ans, i - cur);
	}
	write(ans);
	return 0;
}