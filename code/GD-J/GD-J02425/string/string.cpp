#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	bool b = true;
	long long n, a[200005], k, m;
	char c[200005], s[200005];
	scanf ("%lld", &n);
	for (long long i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
	}
	k = c[1];
	m = a[1];
	for (long long i = 1; i <= n; i ++){
		if (k != c[i]){
			b = false;
		}
		if (m != a[i]){
			m = false;
		}
		for (long long j = 1; j <= a[i]; j ++){
			s[j] == c[i];
		}
	}
	if (b == true){
		cout << 0;
	}
	else if (m == true){
		cout << a[1] * (n / 2);
	}
	else {
		cout << a[2];
	}
	return 0;
}
