#include<bits/stdc++.h>
#define int long long
#define vec vector
#define f(i, l, r) for (int (i) = (l); (i) <= (r); (i) ++)
using namespace std;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vec<int> a(n + 1);
	f(i, 1, n) cin >> a[i];
	if (m == n) {
		int sum = 1;
		f(i, 1, n) sum |= a[i];
		cout << sum << endl;
	} else if (m == 1) {
		int mx = -1;
		f(i, 1, n) mx = max(mx, a[i]);
		cout << mx << endl;
	} else if (m == 2) {
		int mx = 1;
		f(i, 1, n) {
			f(j, i, n) {
				if (i != j) {
					mx = max(mx, a[i] & a[j]);
				}
			}
		}
		cout << mx << endl;
	} else {
		int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
		f(i, 1, n) {
			s1 += (a[i] == 1);
			s2 += (a[i] == 2);
			s3 += (a[i] == 3);
			s4 += (a[i] == 4);
		}
		if (s4 >= m) cout << 4;
		else if (s3 >= m) cout << 3;
		else if (s3 + s2 >= m) cout << 2;
		else cout << 1;
	}
	return 0;
}

