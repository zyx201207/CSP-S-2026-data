#include <bits/stdc++.h>
#include <algorithm>
#define int long long
using namespace std;
int a[200005], l[200005], r[200005];
char c[200005];
int n;
int s1(int x) {
	int wl = 0, wr = n + 1;
	while(wl + 1 < wr) {
		int mid = (wl + wr) / 2;
		if(r[mid] >= x) {
			wr = mid;
		}
		else {
			wl = mid;
		}
	}
	return wr;
}
int s2(int x) {
	int wl = 0, wr = n + 1;
	while(wl + 1 < wr) {
		int mid = (wl + wr) / 2;
		if(l[mid] <= x) {
			wl = mid;
		}
		else {
			wr = mid;
		}
	}
	return wl;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int sz = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sz += a[i];
		l[i] = r[i - 1] + 1;
		r[i] = r[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int wr = sz - l[i] + 1;
		int wl = sz - r[i] + 1;
		if(l[i] > sz / 2) {
			break;
		}
		int s = s1(wl);
		int e = s2(wr);
		for(int j = s; j <= e; j++) {
			if(c[j] != c[i]) {
				if(l[i] <= wl && r[i] >= wr) {
					ans += a[j] - (wl - l[i]) - (r[i] - wr);
				}
				ans += min(abs(r[j] - wl) + 1, min(a[j], abs(l[j] - wr) + 1));
			}
		}
	}
	cout << ans;
	return 0;
}

