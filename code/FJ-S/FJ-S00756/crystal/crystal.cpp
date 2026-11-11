// 100 
// 13 min, shuang 
// easy
// PLEASE CLEAR THE DEQUE!
// Why -1
// Orange/Yellow
#include <bits/stdc++.h>
using namespace std;
#define int ll
using ll = long long; using pi = pair<int, int>;
#define Fr(i, s, t) for (int i(s); i <= (t); ++i)
#define Bk(i, t, s) for (int i(t); i >= (s); --i)
inline int rd() {
	int x(0), f(1), c; while ((c = getchar()) < 48 || c > 57) f = c ^ 45;
	do x = x * 10 + (c & 15); while ((c = getchar()) > 47 && c < 58); return f ? x : -x;
}
constexpr int N = 5e5 + 10;
int n, m, a[N]; deque<int> q;
inline int check(int c) {
	q.clear();
	int sum = 0, mx = -1e12;
	Fr(i, 1, c) {
		sum += a[i], mx = max(mx, a[i]);
	}
	if (mx * c - sum <= m) return 1;
	Fr(i, c + 1, n) {
		sum += a[i] - a[i - c];
		while (!q.empty() && q.front() <= i - c) q.pop_front();
		while (!q.empty() && a[i] > a[q.back()]) q.pop_back();
		q.push_back(i);
		mx = a[q.front()];
	//	cerr << mx << ' ';
		if (mx * c - sum <= m) return 1;
 	}
 //	cerr << endl;
 	return 0;
}
inline void Main() {
    n = rd(), m = rd();
    Fr(i, 1, n) a[i] = rd();
    sort(a + 1, a + n + 1);
    int l = 0, r = n + 1, mid;
    while (l + 1 < r) {
    	mid = l + r >> 1;
    	if (check(mid)) l = mid; else r = mid;
	}
	printf("%lld\n", l);
} signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	Bk(T, 1, 1) Main();
}

