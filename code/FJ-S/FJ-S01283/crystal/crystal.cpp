#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
long long n,m,a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long pan = 1, sum = 0, shu = -1, cha;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	for (long long i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] == a[2] - a[1] && pan == 1) {
			pan = 1;
		} else {
			pan = 0;
		}
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (pan == 1) {
		cha = a[2] - a[1];
		for (long long i = 1; i < n; i++) {
			 m -= i*cha;
			 shu = i;
			if (m < 0) {
				shu = i - 1; 
				break;
			}
		}
		cout << shu + 1;
		return 0;
	} else {
		int maxx = -1;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				long long summ = 0;
				for (int k = i; k < j; k++) {
					summ += a[j] - a[k];
				}
				if (m >= summ) {
					maxx = max(maxx, j - i + 1);
				}
			}
		}
		cout << maxx;
		return 0;
	}
	return 0;
}