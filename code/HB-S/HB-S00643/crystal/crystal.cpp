#include <iostream>
#include <algorithm>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N];
int pre[N];

inline bool check(int len) {
	F(l, 1, n - len + 1) {
		int r = l + len - 1;
		int cst = len * a[r] - (pre[r] - pre[l - 1]);
		if (cst <= m) return 1;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	F(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	F(i, 1, n) pre[i] = pre[i - 1] + a[i];
	
	int p = 1, q = n;
	while (p < q) {
		int mid = (p + q + 1) / 2;
		if (check(mid)) p = mid;
		else q = mid - 1;
	}
	
	cout << p;
	return 0;
}
