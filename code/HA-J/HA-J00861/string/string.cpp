#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
ll a[N], n, sum, mid, ans, l, r;
string c;

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		sum += a[i]; 
	}
	if (sum & 1) {
		mid = sum / 2 + 1;
		ll cnt = 0, s = 0, f = 0, id = 0;
		for (int i = 1; i <= n; i ++) {
			if (cnt + a[i] >= mid) {
				s = cnt + 1;
				f = cnt + a[i];
				id = i;
				break;
			}
			cnt += a[i];
		}
		if (mid - s == f - mid) {
			l = id - 1;
			r = id + 1;
		}
		else if (mid - s < f - mid) {
			a[id] -= ((mid - s) * 2 + 1);
			l = id - 1;
			r = id;
		}
		else {
			a[id] -= ((f - mid) * 2 + 1);
			l = id;
			r = id + 1;
		}
	}
	else {
		mid = sum / 2;
		ll cnt = 0, s = 0, f = 0, id = 0;
		for (int i = 1; i <= n; i ++) {
			if (cnt + a[i] == mid) {
				l = i;
				r = i + 1;
				break;
			}
			else if (cnt + a[i] > mid) {
				s = cnt + 1;
				f = cnt + a[i];
				id = i;
				break;
			}
			cnt += a[i];
		}
		if (f - mid <= mid - s) {
			a[id] -= ((f - id) * 2);
			if (a[id] == 0) {
				l = id - 1;
				r = id + 1;
			}
			else {
				l = id;
				r = id + 1;
			}
		}
		else {
			a[id] -= ((mid + 1 - s) * 2);
			l = id - 1;
			r = id + 1;
		}
	}
	while (l >= 1 || r <= n) {
		if (c[l] != c[r]) ans += min(a[l], a[r]);
		if (a[l] > a[r]) {
			a[l] -= a[r];
			r ++;
		}
		else if (a[l] == a[r]) {
			l --;
			r ++;
		}
		else {
			a[r] -= a[l];
			l --;
		}
	}
	cout << ans;
	return 0;
}

