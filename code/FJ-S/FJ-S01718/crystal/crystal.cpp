#include <bits/stdc++.h>
#define inf LLONG_MAX

using namespace std;
const int N = 5e5 + 10;
 
long long n, m;
long long d[N];
vector < long long> a;
long long mn = inf, mx = -inf;
 
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	perror("freopen");
	cin >> n >> m;
//	if (n <= 5000) {
//		a.push_back(inf);
//		for (int i = 1; i <= n; ++i) {
//			long long x; cin >> x;
//			a.push_back(x);
//			mn = min(mn, x);
//			mx = max(mx, x);
//		}
//		sort(a.begin(), a.end());
//		long long ret = 0;
//		for (int i = mn; i <= mx; ++i) {
//			for (int j = 1; j <= n; ++j)
//				d[j] = i - a[j];
//			sort(d + 1, d + n + 1);
//			long long cnt = 0;
//			for (int j = 1; j <= n; ++j)
//				if (d[j] >= 0 && m - d[j] >= 0) ++cnt, m -= d[j];
//			ret = max(cnt, ret);
//		}
//		cout << ret << '\n';
//		return 0;	
//	}
	a.push_back(inf);
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	long long mid = a[(n + 1) / 2];
	long long rett = 0, res = 0;
	for (int i = 1; i <= n; ++i) {
		long long t = 0;
		while (a[i + 1] == a[i]) ++i, ++t;
		if (rett < t) {
			rett = t;
			if (abs(a[i] - mid) < abs(res - mid))
				res = a[i];
		}
	}
	int cnt1 = 0, cnt2 = 0;
	if (rett == 0) {
		for (int i = 1; i <= n; ++i)
			d[i] = abs(mid - a[i]);
		sort(d + 1, d + n + 1);
		for (int i = 1; i <= n; ++i) {
			if (m >= d[i]) {
				++cnt1; m -= d[i];
			}
		}
		cout << cnt1 << '\n';
	} else {
		for (int i = 1; i <= n; ++i)
			d[i] = abs(res - a[i]);
		sort(d + 1, d + n + 1);
		for (int i = 1; i <= n; ++i) {
			if (m >= d[i]) {
				++cnt2; m -= d[i];
			}
		}
		cout << cnt2 << '\n'; 
	}
	return 0;
} 


