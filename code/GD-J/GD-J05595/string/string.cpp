#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n, o = 0, cnt = 0;
	bool j = false;
	cin >> n;
	string a;
	for (long long h = 0; h < n; h++) {
		long long i;
		char z;
		cin >> i >> z;
		if (i < 100000000) {
			for (long long j = o; j < i + o; j++) {
				a[j] = z;
			}
		} else {
			j = true;
			i = i / 100000000;
			for (long long j = o; j < i + o; j++) {
				a[j] = z;
			}
		}
		o = i;
		cnt += i;
	}
	long long s = 0;
	for (long long i = 0; i < (cnt - 1) / 2; i++) {
		if (a[i] != a[cnt - 1 - i] && a[cnt - 1 - i]) s++;
	}
	if (j) {
		cout << s * 100000000 << endl;
		return 0;
	}
	cout << s;
	return 0;
}
