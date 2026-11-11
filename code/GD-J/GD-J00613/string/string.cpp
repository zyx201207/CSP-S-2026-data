#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define N 200010

int n;
int a[N];
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> c[i];
	}
	int ans = 0;
	int l = 1, r = n;
	int lsum = 0, rsum = 0;
	while(l < r) {
		lsum += a[l], rsum += a[r];
		if(lsum < rsum) {
			a[r] -= a[l];
			if(c[l] != c[r]) {
				ans += a[l];
			}
			rsum = lsum;
			l++;
		} else if(lsum > rsum) {
			a[l] -= a[r];
			if(c[l] != c[r]) {
				ans += a[r];
			}
			lsum = rsum;
			r--;
		} else {
			if(c[l] != c[r]) {
				ans += a[r];
			}
			l++, r--;
		}
	}
	cout << ans << "\n";
	return 0;
}
