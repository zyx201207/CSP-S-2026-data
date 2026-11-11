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

const int N = 500010;
int n, m, a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i ++) a[i] = read();
	sort(a + 1, a + 1 + n); 
	int d = 0, l = 1, res = 0;
	for (int i = 1; i <= n; i ++) {
		d += (i - l) * (a[i] - a[i - 1]);
		while (d > m && l < i) d -= a[i] - a[l], l ++;
		res = max(res, i - l + 1);   
	} 
	printf("%lld\n", res);
	return 0;
}

