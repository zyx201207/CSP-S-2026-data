#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int l, r;
int a[N];
char c[N];
long long ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	l = 1, r = n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	while(l < r) {
		if(c[l] == c[r]) {
			if(a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else {
				a[l] -= a[r];
				r--;
				if(a[l] == 0) l++;
			}
		} else {
			if(a[l] < a[r]) {
				a[r] -= a[l];
				ans += a[l];
				l++;
			} else {
				a[l] -= a[r];
				ans += a[r];
				r--;
				if(a[l] == 0) l++;
			}
		}
	}
	cout << ans;
	return 0;
}
