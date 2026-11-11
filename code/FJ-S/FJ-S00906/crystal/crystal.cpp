#include <iostream>
#include <cctype>
#include <algorithm>
#define gc getchar
#define pc putchar
#define int long long
using namespace std;
const int N = 500005, M = 1e12;
int n, m, a[N], sum[N], ans;
inline void rd(int &x) {
	int sum = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
	for (; isdigit(c); c = gc()) sum = sum * 10 + c - '0';
	x = sum * f;
}
inline void pt(int x) {
	if (x > 9) pt(x/10);
	pc(x%10+'0');
}
inline void wt(int x) {
	if (x < 0) {pc('-'); x = -x;}
	pt(x);
}
bool check(int x, int y) { // 填满 x 以左的 y 列要操作多少次 
	unsigned int need = - sum[x-1] + sum[x-y-1] + y * a[x];
//	wt(need);pc('\n');
	return need <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	rd(n); rd(m);
	for (int i = 1; i <= n; i++) {
		rd(a[i]); a[i] += M;
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i]; // 前缀和 
	}
	for (int i = 1; i <= n; i++) { // 追平至 a[i] 
		int l = 0, r = i - 1;
		while (l + 1 < r) { // 二分答案：m 次能够填满 i 以左的几列 
			int mid = l + r >> 1;
			if (check(i, mid)) l = mid;
			else r = mid - 1;
		}
		if (l > r) swap(l, r);
		if (check(i, r)) ans = max(ans, r+1);
		else ans = max(ans, l+1);
	}
	wt(ans);
	return 0;
}
