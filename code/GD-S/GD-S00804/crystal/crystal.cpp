#include<bits/stdc++.h>
#define int long long
#define f(i, l, r) for (int (i) = (l); (i) <= (r); (i) ++)
#define vec vector
using namespace std;
signed main() {
	freopen("crystal4.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vec<int> a(n + 1, 0);
	f(i, 1, n) cin >> a[i];
	sort(a.begin() + 1, a.end());
	int ans = 0;
	f(i, 2, n) {
		int mm = m;
		for (int j = i - 1; j >= 1; j--) {
			int b = a[i] - a[j];
			if (mm >= b) {
				mm -= b;
				ans = max(ans, i - j + 1);
//				cout << i << ' ' <<j << endl;
//				cout << mm << ' ' << b << endl;
			} else break;
		}
	}
	cout << ans << endl;
	return 0;
} 
