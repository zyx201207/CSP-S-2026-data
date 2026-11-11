#include <iostream>
#include <algorithm>
#define N 200005
using namespace std;

typedef long long ll;

ll n, a[N], s[N], ss, L[N], R[N], l1[N], r1[N], s1[N], l2[N], r2[N], s2[N], cnt1, cnt2;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++) {
		char c;
		cin >> a[i] >> c;
		s[i] = c - 'a' + 1;
		ss += a[i];
		L[i] = R[i - 1] + 1;
		R[i] = R[i - 1] + a[i];
	}
	ll tt = ss / 2;
//	cout << tt << "\n";
	for(ll i = 1; i <= n; i++) {
		if(L[i] <= tt && R[i] > tt) {
			if(n & 1) {
				l1[++cnt1] = L[i], r1[cnt1] = tt, s1[cnt1] = s[i];
				if(R[i] >= tt + 2) l2[++cnt2] = ss - R[i] + 1, r2[cnt2] = ss - tt - 1, s2[cnt2] = s[i];
			} else {
				l1[++cnt1] = L[i], r1[cnt1] = tt, s1[cnt1] = s[i];
				l2[++cnt2] = ss - R[i] + 1, r2[cnt2] = ss - tt, s2[cnt2] = s[i];
			}
		} else if(L[i] > tt) {
			if(n & 1 && L[i] == tt + 1) {
				if(R[i] == tt + 1) continue;
				else l2[++cnt2] = ss - R[i] + 1, r2[cnt2] = ss - tt - 1, s2[cnt2] = s[i];
			} else l2[++cnt2] = ss - R[i] + 1, r2[cnt2] = ss - L[i] + 1, s2[cnt2] = s[i];
		} else {
			l1[++cnt1] = L[i], r1[cnt1] = R[i], s1[cnt1] = s[i];
		}
	}
	reverse(l2 + 1, l2 + cnt2 + 1);
	reverse(r2 + 1, r2 + cnt2 + 1);
	reverse(s2 + 1, s2 + cnt2 + 1);
//	for(ll i = 1; i <= cnt2; i++) {
//		cout << l2[i] << " " << r2[i] << " " << s2[i] << "\n";
//	}
	ll i = 1, j = 1, cnt = 0;
	while(i <= cnt1 && j <= cnt2) {
		ll tl = max(l1[i], l2[j]), tr = min(r1[i], r2[j]);
		if(s1[i] != s2[j]) cnt += tr - tl + 1;
//		cout << i << " " << 
		if(r1[i] <= r2[j]) i++;
		else j++;
	}
	cout << cnt;
}

// Yellow

// CSP ¼õ J ³ıÒÔ S ºÜÄÑ 
