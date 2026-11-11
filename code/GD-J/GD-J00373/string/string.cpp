#include <bits/stdc++.h>
#define int long long
#define F(i, s, t) for (int (i) = (s); (i) <= (t); ++(i))
#define outs(s) cout << (s) << ' '
#define outn(s) cout << (s) << '\n'
#define FILENAME "string"
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	
	const int N = 2e5+5;
	int n, a[N];
	int ans = 0;
	char c[N];
	cin >> n;
	F(i, 1, n) cin >> a[i] >> c[i];
	int l = 1;
	int r = n;
	while (l < r) {
		if (a[l] < a[r]) {
			if (c[l] != c[r]) {
				ans += a[l];
			}
			a[r] -= a[l];
			l++;
		}
		else if (a[l] > a[r]) {
			if (c[l] != c[r]) {
				ans += a[r];
			}
			a[l] -= a[r];
			r--;
		}
		else {
			if (c[l] != c[r]) {
				ans += a[l];
			}
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
} 
