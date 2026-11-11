#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN (int(2e5+5))
#define ll long long
ll n, a[MAXN], cnt, ans;
char c[MAXN];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		cnt += a[i];
	}
	ll half = (cnt + 1ll) / 2ll, tmp = 0, x = 0;
	for(ll i = 1; i <= n; i++) {
		if(tmp + a[i] >= half) {
			x = i;
			break;
		}
		tmp += a[i];
	}
	ll cntl = half - tmp, cntr = tmp + a[x] - half;
	if(cnt%2)cntl--;
	ll l = x, r = x;
	while(l >= 1 && r <= n) {
		if(c[l]==c[r]) {
			if(cntl > cntr) {
				cntl -= cntr,r++,cntr = a[r];
			} else {
				cntr -= cntl,l--,cntl = a[l];
			}
		} else {
			ans += min(cntl, cntr);
			if(cntl > cntr) {
				cntl -= cntr,r++,cntr = a[r];
			} else {
				cntr -= cntl,l--,cntl = a[l];
			}
		}
	}
	cout << ans;
	return 0;
}

/*


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
