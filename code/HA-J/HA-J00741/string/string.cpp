#include <bits/stdc++.h>
using namespace std;
long long c[200003];
char a[200003];
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i] >> a[i];
	}
	long long l = 1, r = n, sum = 0; 
	while (l < r) {
		if (a[l] != a[r]) {
			if (c[r] > c[l]) {
				l ++;
				c[r] -= c[l];
				sum += c[l];
			}else if (c[r] < c[l]) {
				r --;
				c[l] -= c[r];
				sum += c[r];
			}else {
				l ++, r --;
				sum += c[r];
			}
		}else {
			if (c[r] > c[l]) {
				l ++;
				c[r] -= c[l];
			}else if (c[r] < c[l]) {
				r --;
				c[l] -= c[r]; 
			}else {
				l ++;
				r --;
			}
		}
	}
	cout << sum;
	return 0;
}





