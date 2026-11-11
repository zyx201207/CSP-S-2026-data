#include<bits/stdc++.h>
using namespace std;
long long n, a[1010101], suml, sumr, ans;
char c[1010101];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) cin >> a[i] >> c[i];
	long long l = 1, r = n;
	suml = a[l];
	sumr = a[r];
	while (l <= r) {
		char cl = c[l], cr = c[r];
		if (cl != cr) {
			if (suml == sumr) {
				ans += suml;
				l++;
				suml = a[l];
				r--;
				sumr = a[r];
			}
			else if (suml > sumr) {
				ans += sumr;
				suml -= sumr;
				r--;
				sumr = a[r];
			}
			else {
				ans += suml;
				sumr -= suml;
				l++;
				suml = a[l];
			}
		}
		else {
			if (suml == sumr) {
				l++;
				suml = a[l];
				r--;
				sumr = a[r];
			}
			else if (suml > sumr) {
				suml -= sumr;
				r--;
				sumr = a[r];
			}
			else {
				sumr -= suml;
				l++;
				suml = a[l];
			}
		}
	}
	cout << ans;
}
