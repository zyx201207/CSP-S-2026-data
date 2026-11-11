#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct C {
	ll num;
	char c;
}a[200010], b[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	ll tot = 0;
	for(ll i=1; i<=n; i++) {
		cin >> a[i].num >> a[i].c;
		b[i].num = a[i].num, b[i].c = a[i].c;
		tot += a[i].num;
	}
	ll mid = tot / 2;
	ll mid1, mid2;
	mid1 = mid2 = mid;
	ll l = 1, r = n;
	ll ans = 0;
	while(true) {
		if(l == r) break;
		if(mid1 - b[l].num >= 0 && mid2 - b[r].num >= 0) {
			if(a[l].num == a[r].num) {
				if(a[l].c != a[r].c) {
					ans += a[r].num;
//					cout << a[r].num << " " << a[r].c << " " << a[l].c;
				}
//				cout << endl;
				if(l+1 == r) break;
				l++, r--;
				continue;
			}
			if(a[l].num > a[r].num) {
				if(a[l].c != a[r].c) {
					ans += a[r].num;
//					cout << a[r].num << " " << a[r].c << " " << a[l].c;
				}
				a[l].num -= a[r].num;
				r--;
			} else {
				if(a[l].c != a[r].c) {
					ans += a[l].num;
//					cout << a[l].num << " " << a[l].c << " " << a[r].c;
				}
				a[r].num -= a[l].num;
				l++;
			}
		} else {
			if(mid1 - b[l].num < 0) {
				while(true) {
					if(l == r) break;
					if(a[l].c != a[r].c) {
						ans += a[r].num;
//						cout << a[r].num << " " << a[r].c << " " << a[l].c;
					}
					r--;
//					cout << endl;
				}
			}
			if(mid1 - b[r].num < 0) {
				while(true) {
					if(l == r) break;
					if(a[l].c != a[r].c) {
						ans += a[l].num;
//						cout << a[l].num << " " << a[l].c << " " << a[r].c;
					}
					l++;
//					cout << endl;
				}
			}
		}
//		cout << endl;
	}
	cout << ans;
	return 0;
}

