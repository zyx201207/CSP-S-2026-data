#include <bits/stdc++.h>
const int N = 2e5 + 10;
using namespace std;
char c[N];
long long n, a[N], ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i] >> c[i];
	long long l = 1, r = n;
	while(l < r) {
		char k1 = c[l], k2 = c[r];
		long long t1 = a[l], t2 = a[r];
		if(k1 == k2) {
			if(t1 > t2) {
				r --;
				a[l] -= t2;
			}
			if(t1 < t2)  {
				l ++;
				a[r] -= t1;
			}
			if(t1 == t2) {
				r --;
				l ++;
			}
		}
		else {
			if(t1 > t2) {
				a[l] -= t2;
				r --;
				ans += t2;
			}
			if(t1 < t2) {
				a[r] -= t1;
				l ++;
				ans += t1;
			}
			if(t1 == t2) {
				l ++;
				r --;
				ans += t1; 
			}
		}
	}
	cout << ans;
	return 0;
}
