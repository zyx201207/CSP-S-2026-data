#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], p[N], lt[35], rt[35], q;
unordered_map <int, int> cnt;
vector <int> v;
int n, m;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	p[0] = 1;
	for (int i = 1; i <= 30; ++i) p[i] = p[i - 1] * 2;
	for (int i = 1; i <= n; ++i) cin >> a[i], cnt[a[i]]++;
	sort(a + 1, a + 1 + n);
	int maxi = 0, maxi2 = 1;
	for (int i = n; i >= n - m; --i) maxi2 &= a[i];
	for (int i = n; i >= 1; --i) {
		if (cnt[a[i]] >= m) {
			maxi = a[i];
			break;
		}
	}
	for (int i = 1; i <= 30; ++i) {
		if (p[i - 1] > a[n]) break;
		int l = 0, r = 0;
		for (int j = 1; j <= n; ++j) {
			if (a[j] > p[i]) break;
			if (a[j] >= p[i - 1] + 1 && a[j] <= p[i] - 1 && !l) l = j;
			if (a[j] >= p[i - 1] + 1 && a[j] <= p[i] - 1) r = j;
		}
		lt[i] = l, rt[i] = r;
//		cout << l << ' ' << r << "\n";
	}
	q = 0;
	int ans2 = 1, m2 = m;
	for (int i = 30; i >= 1; --i) {
		if (!lt[i] && !rt[i]) continue;
		if (m2 <= 0) break;
		int t1 = a[lt[i]];
		for (int j = rt[i]; j >= lt[i]; --j) {
			t1 &= a[j];
			m2--;
			if (m2 <= 0) break;
		}
		ans2 &= t1;
	}
	while (m - 1 >= 0) {
		for (int i = 30; i >= 1 && m >= 0; --i) {
			if (!lt[i] && !rt[i]) continue;
			if (rt[i] - q < lt[i]) continue;
			m -= cnt[a[rt[i] - q]];
			v.push_back(a[rt[i]]);
		}
		q++;
	}
	int ans = v[0];
	for (auto x : v) ans &= x;
	cout << max({ans, maxi, ans2, maxi2});
	return 0;
}
