#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], ans;
int c[N];
int t[N * 4], sum[N * 4];
inline void build(int p = 1, int l = 2, int r = n) {
	if (l == r) {
		t[p] = sum[p] = c[l];
		return;
	}int mid = l + r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	sum[p] = sum[p << 1] + sum[p << 1 | 1];
	t[p] = t[p << 1] + sum[p << 1 | 1] * (mid - l + 1)+ t[p << 1 | 1];
}
inline int query_sum(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) 
		return sum[p];
	int mid = l + r >> 1, res = 0;
	if (L <= mid) res = query_sum(p << 1, l, mid, L, R);
	if (R > mid) res += query_sum(p << 1 | 1, mid + 1, r, L, R);
	return res;
} 
inline int query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) 
		return t[p];
	int mid = l + r >> 1;
	if (R <= mid) return query(p << 1, l, mid, L, R);
	if (L > mid) return query(p << 1 | 1, mid + 1, r, L, R);
	return query(p << 1, l, mid, L, mid) + query(p << 1 | 1, mid + 1, r, mid + 1, R)
		 + query_sum(p << 1 | 1, mid + 1, r, mid + 1, R) * (mid - L + 1);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		c[i] = a[i] - a[i - 1];
	build();
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i - 1, res = 0;
		while (l <= r) {
			int mid = l + r >> 1, tmp;
			tmp = query(1, 2, n, mid + 1, i);
			if (tmp <= m) {
				r = mid - 1;
				res = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
} 
