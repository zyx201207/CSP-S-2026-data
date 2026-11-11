#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5;
ll a[N];
char ch[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i] >> ch[i];
	ll l = 1, r = n, ans = 0;
	while(l < r) {
		if(a[l] < a[r]) {
			if(ch[l] != ch[r]) ans += a[l];
			a[r] -= a[l];
			l++;
		}
		else if(a[l] == a[r]) {
			if(ch[l] != ch[r]) ans += a[l];
			l++;
			r--;
		}
		else {
			if(ch[l] != ch[r]) ans += a[r];
			a[l] -= a[r];
			r--;
		}
	}
	cout << ans << endl;
	return 0;
}
