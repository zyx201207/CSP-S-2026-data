//GZ-S00285 张苇然 实验三中 
#include <bits/stdc++.h>
#define ll long long
#define vll vector <ll>
#define sll set <ll>
#define inf LLONG_MAX
using namespace std;

int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	vll a (n + 1,0);
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a.begin() + 1,a.end());
	ll s = a[2] - a[1];
	bool f = 1;
	for (int i = 3;i <= n;i++) {
		if (a[i] - a[i - 1] != s) {
			f = 0;
			break;
		}
	}
	if (f) {
		ll i;
		for (i = 1;i * (i + 1) * s / 2 <= m;i++) ;
		cout << i;
	} 
	else if (n <= 5000) {
		ll ma = 1;
		for (int j = 1;j <= n;j++) {
			vll b;
			for (int i = 1;i <= n;i++) {
				if (a[i] <= a[j]) {
					b.push_back(a[j] - a[i]);
				}
				else break;
			}
			sort(b.begin(),b.end());
			ll cnt = 0,k = m;
			for (int i = 0;i < (ll)b.size();i++) {
				if (k - b[i] >= 0) {
					k -= b[i];
					cnt++;
				}
				else break;
			}
			ma = max(ma,cnt);
		}
		cout << ma;
	}
	else {
		vll b (n + 1,0),c (n + 1,0);
		for (int i = 1;i <= n;i++) {
			b[i] = a[n] - a[i];
			c[i] = b[i] + c[i - 1];
		}
		ll l = 1,r = 2,ma = 1;
		while (l <= r && r <= n) {
			if (c[r - 1] - c[l - 1] - (r - l) * b[r] <= m) {
				ma = max(ma,r - l + 1);
				r++;
			}
			else {
				l++;
			}
		}
		cout << ma;
	}
	return 0;
}
