#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct ii {
	long long s;
	char z;
};

ii a[N], b[N], c[N];
long long sum = 0, sum1, sum2;
long long n, an, bn;

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].z;
		sum += a[i].s;
//		cout << sum << endl;
	}
	
	bool x = sum % 2;
	sum >>= 1;
//	cout << sum << endl;
	for (int i = 1; i <= n; i++) {
		if (sum == 0) {
			c[++bn].s = a[i].s;
			c[bn].z = a[i].z;
			if (x) c[bn].s--;
			x = 0;
		} else if (sum - a[i].s >= 0) {
			sum -= a[i].s;
			b[++an].s = a[i].s;
			b[an].z = a[i].z;
		} else {
			b[++an].s = sum;
			b[an].z = a[i].z;
			c[++bn].s = a[i].s - sum - (x ? 1 : 0);
			c[bn].z = a[i].z;
			if (c[bn].s == 0) bn--;
			sum = 0;
			x = 0;
		}
//		cout << sum << endl;
	}
	
//	for (int i = 1; i <= an; i++) sum1 += b[i].s;//cout << b[i].z << ' ' << b[i].s << endl;
////	cout << endl;
//	for (int i = 1; i <= bn; i++) sum2 += c[i].s;//cout << c[i].z << ' ' << c[i].s << endl;
	
	long long xz = 0, jl = bn, ans = 0;
	for (int i = 1; i <= an; i++) {
		xz = b[i].s;
		while (xz != 0) {
//			cout << ans << endl;
			if (xz >= c[jl].s) {
				if (b[i].z != c[jl].z) ans += c[jl].s;
				xz -= c[jl].s;
				jl--;
			} else {
				if (b[i].z != c[jl].z) ans += xz;
				c[jl].s -= xz;
				xz = 0;
			}
		}
	}
	
	cout << ans; //<< endl << sum1 << ' ' << sum2;
	return 0;
}
