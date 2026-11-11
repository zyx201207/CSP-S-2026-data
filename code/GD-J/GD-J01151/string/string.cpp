#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;

int n, a[N]; char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	ll l = 1, r = 0;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i] >> c[i], r += a[i];
	
	ll ans = 0;
	int lpos = 1, rpos = n;
	while (l < r) {
		if (lpos == rpos) break;
		if (a[lpos] < a[rpos]) {
			if (c[lpos] != c[rpos]) {
				ans += a[lpos];
			}
			l += a[lpos];
			a[rpos] -= a[lpos], r -= a[lpos];
			a[lpos++] = 0; 
		} else if (a[lpos] > a[rpos]) {
			if (c[lpos] != c[rpos]) {
				ans += a[rpos];
			}
			r -= a[rpos];
			a[lpos] -= a[rpos], l += a[rpos];
			a[rpos--] = 0; 
		} else if (a[lpos] == a[rpos]) {
			if (c[lpos] != c[rpos]) ans += a[lpos];
			l += a[lpos], r -= a[lpos];
			a[lpos] = a[rpos] = 0, lpos++, rpos--;
		}
	}	
	
	cout << ans;
    return 0;
} 
