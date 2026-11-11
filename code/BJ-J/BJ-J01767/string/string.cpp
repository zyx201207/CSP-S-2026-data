#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
string str[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> str[i];
	}
	int l = 1, r = n;
	ll sum = 0;
	while (l < r) {
		if (str[l] == str[r]) {
			if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else if (a[r] < a[l]) {
				a[l] -= a[r];
				r--;
			} else {
				l++;
				r--;
			}
			continue;
		}
		sum += min(a[l], a[r]);
		if (a[l] < a[r]) {
			a[r] -= a[l];
			l++;
		} else if (a[l] > a[r]) {
			a[l] -= a[r];
			r--;
		} else {
			l++;
			r--;
		}
	}
	cout << sum << endl;
	return 0;
}
