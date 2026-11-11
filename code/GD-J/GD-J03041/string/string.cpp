#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

//	ios::sync_with_stdio(false);
//	cin.tie(nullptr), cout.tie(nullptr);

	long long n, ans = 0;
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}

	long long l = 1, r = n;
	while(l != r) {
		if(c[l] == c[r]) {
			if(a[l] < a[r]) {
				a[r] = a[r] - a[l];
				a[l] = 0, l = l + 1;
			} else {
				a[l] = a[l] - a[r];
				a[r] = 0, r = r - 1;
			}
		} else {
			if(a[l] < a[r]) {
				a[r] = a[r] - a[l];
				ans = ans + a[l];
				a[l] = 0, l = l + 1;
			} else {
				a[l] = a[l] - a[r];
				ans = ans + a[r];
				a[r] = 0, r = r - 1;
			}
		}
	}
	cout << ans;
	return 0;
}
