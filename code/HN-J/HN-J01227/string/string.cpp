#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2000005;
ll n,len,ans;
char a[MAXN];
/*struct info{
	char v;
	ll begins, ends;
}a[MAXN];

ll find_dy(ll k) {
	ll l = 1, r = n, mid = 0;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (a[mid].ends >= k) r = mid;
		else l = mid + 1;
	}
	return l;
}
ll find_xy(ll k) {
	ll l = 1, r = n, mid = 0;
	while (l + 10 < r) {
		mid = l + (r - l) / 2;
		if (a[mid].begins <= k) l = mid;
		else r = mid - 1;
	}
	for (int i = l; i < r; i++) {
		if(a[i].begins < k) mid = i;
	}
	return mid;
}*/
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	/*ll past = 0;
	for (ll i = 1; i <= n; i++) {
		ll sr;
		char c;
		cin >> sr >> c;
		a[i].v = c;
		a[i].begins = past + 1;
		a[i].ends = past + sr;
		past += sr;
	}
	
	for (ll i = 1; i <= n; i++){
		
	}*/
	ll past = 0, amp = 0;
	for (ll i = 1; i <= n; i++) {
		ll sr;
		char c;
		cin >> sr >> c;
		for(ll i = past + 1; i <= past + sr; i++) a[i] = c;
		past += sr;
		len += sr;
		amp = len;
	}
	len = (len % 2 == 0) ? len / 2 : len / 2 + 1;
	for (ll i = 1; i <= len; i++) 
		if (a[i] != a[amp - i + 1]) ans++;
	cout << ans;
	return 0;
}
