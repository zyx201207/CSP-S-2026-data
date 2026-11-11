/*
10:41 qie T2 ( )
*/
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

#define N 200005

ll n, a[N], ans;
ll b[N];
char c[N], d[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b[n - i + 1] = a[i];
		d[n - i + 1] = c[i];
	}
	
	for (ll l = 1, r = 1; l <= n && r <= n; ) {
		if (a[l] < b[r]) {
			if (c[l] != d[r]) ans += a[l];
			b[r] -= a[l];
			l++;
		} else if (a[l] > b[r]) {
			if (c[l] != d[r]) ans += b[r];
			a[l] -= b[r];
			r++;
		} else {
			if (c[l] != d[r]) ans += a[l];
			l++, r++;
		}
	}
	
	cout << (ans + 1) / 2;

	return 0;
}

