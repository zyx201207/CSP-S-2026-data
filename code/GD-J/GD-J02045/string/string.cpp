#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
using ll = long long;
ll n, a[maxn], pre[maxn], ans;
char c[maxn];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		pre[i] = pre[i - 1] + a[i];
	}
	ll i = 1, j = n, l = 1, r = pre[n], suma = pre[n];
	ll mid = (suma + 1) / 2, lmid, rmid;
	if(suma % 2 == 1) {
		lmid = mid - 1;
		rmid = mid + 1;
	}
	else {
		lmid = mid;
		rmid = mid + 1;
	}
	while(l <= mid && r >= mid) {
		ll tol = min(pre[i] + 1, mid + 1), tor = max(pre[j - 1], mid - 1);
		ll lenl = tol - l, lenr = r - tor, cnts = 0;
		if(lenl == lenr) {
			if(c[i] == c[j])
				cnts = lenl;
			l = tol;
			i ++;
			r = tor;
			j --;
		}
		else if(lenl < lenr) {
			if(c[i] == c[j])
				cnts = lenl;
			l = tol;
			i ++;
			r -= lenl;
		}
		else { // lenl > lenr
			if(c[i] == c[j])
				cnts = lenr;
			r = tor;
			j --;
			l += lenr;
		}
		if(cnts == 0)
			ans += min(lenl, lenr);
	}
	cout << ans << '\n';
	return 0;
} 
