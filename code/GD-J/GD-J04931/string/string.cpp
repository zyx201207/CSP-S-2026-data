#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
long long a[N];
char c[N];

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	
	if (n % 2) a[n / 2]--;
	long long i = 0, j = n - 1, ans = 0;
	while (i != j) {
		if (a[i] > a[j]){
			if (c[i] != c[j]) ans += a[j];
			a[i] -= a[j--];
		}
		else {
			if (c[i] != c[j]) ans += a[i];
			a[j] -= a[i++];
		}
	}
	
	cout << ans;
	
	return 0;
}
