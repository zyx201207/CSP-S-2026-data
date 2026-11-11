#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans, n, cn, icn[200010];
bool b[200010];
char c[200010];
int main(){
	freopen("string4.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (ll i = 1, ncn; i <= n; ++i) {
		char nc;
		scanf("%lld", &ncn);
		cin >> nc;
		if (i == 1) {
			icn[++cn] = ncn;
			c[cn] = nc;
		} else {
			if (c[cn] == nc){
				icn[cn] += ncn;
			} else {
				icn[++cn] = ncn;
				c[cn] = nc;
			}
		}
	}
	ll li = 1, ri = cn;
	while (1) {
		if (c[li] != c[ri]) {
			while (b[li]) {
				++li;
			}
			while (b[ri]) {
				--ri;
			}
			if (li >= ri) {
				break;
			}
			b[li] = 1;
			b[ri] = 1;
			if (li + 1 == ri) {
				ans += min(icn[li], icn[ri]);
			} else {
				ans += max(icn[li], icn[ri]);
				if (icn[li] > icn[ri]) {
					icn[ri - 1] -= icn[li] - icn[ri];
					ll oinc;
					while (icn[ri - 1] <  0 && li < ri) {
						icn[ri - 2] += icn[ri - 1];
						--ri;
						oinc = icn[ri];
						icn[ri] = 0;
						b[ri] = 1;
					}
					if (li >= ri) {
						ans += oinc;
						break;
					}
				} else {
					icn[li + 1] -= icn[ri] - icn[li];
					ll oinc;
					while (icn[li + 1] <  0 && li < ri) {
						icn[li + 2] += icn[li + 1];
						++li;
						oinc = icn[li];
						icn[li] = 0;
						b[li] = 1;
					}
					if (li >= ri) {
						ans += oinc;
						break;
					}
				}
			}
		}
		++li;
		--ri;
	}
	printf("%lld", ans);
	return 0;
}
