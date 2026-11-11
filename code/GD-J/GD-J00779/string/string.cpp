#include<bits/stdc++.h>
#define int long long
#define vec vector
#define f(i, l, r) for (int (i) = (l); (i) <= (r); (i) ++)
using namespace std;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vec<int> a(n + 1);
	vec<char> c(n + 1);
	string s = "";
	f(i, 1, n) {
		cin >> a[i] >> c[i];
		f(j, 1, a[i]) {
			s += c[i];
		}
	}
	int t = s.size();
	string rs = s;
	int ans = 0;
	reverse(s.begin(), s.end());
	f(i, 0, t - 1) if (rs[i] != s[i]) ans ++;
	cout << ans / 2 << endl;
	return 0;
} 
