#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 500005
long long n, m, a[MAXN], dif[MAXN], s[MAXN], ans;
bool check(long long x, long long y) {
	long long re = 0;
	for(long long i = x; i < y; i++)
		re += s[y] - s[i];
	return (re <= m);
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(n <= 5000) {
		for(long long i = 2; i <= n; i++)
			dif[i] = a[i] - a[i-1];
		for(long long i = 1; i <= n; i++)
			s[i] = s[i-1] + dif[i];
		for(long long i = 1; i <= n; i++) {
			long long l = 1, r = i, tmp = i;
			while(l < r) {
				long long mid = (l + r) / 2ll;
				if(check(mid, i)) {
					r = mid - 1;
					tmp = mid;
				} else {
					l = mid + 1;
				}
			}
			ans = max(ans, i-tmp+1);
		}
	} else {
		for(long long i = 2ll; i <= n; i++)
			dif[i] = a[i] - a[i-1ll];
		long long l = 1ll, r = 1ll, k = 0ll;
		for(; r <= n; r++) {
			while(l < r && m < k) {
				l++;
				k -= dif[l];
			}
			ans = max(ans, r - l + 1ll);
			k += (r - l + 1ll) * dif[r+1ll];
		}
	}
	cout << ans;
	return 0;
}

/*

5 5
1 2 4 8 9

-3 -2 -1
+1  +1
*/
