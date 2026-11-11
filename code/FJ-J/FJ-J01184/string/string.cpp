#include<iostream>
using namespace std;
int n;
int a[20005];
char b[20005];
int l = 1, r, p;
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	r = n;
	while(true) {
		if (l >= r) break;
		if (b[l] != b[r]) {
			if (a[l] == a[r]) p += a[l], l++, r--;
			else if (a[l] > a[r]) p += a[r], a[l] -= a[r], r--; 
			else p += a[l], a[r] -= a[l], l++;
		}
		else {
			if (a[l] == a[r]) l++, r--;
			else if (a[l] > a[r]) a[l] -= a[r], r--;
			else a[r] -= a[l], l++;
		}
	}
	cout << p;
	return 0;
}
