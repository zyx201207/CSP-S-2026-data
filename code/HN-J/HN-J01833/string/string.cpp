#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long sum;
long long j;
int n;
char c[N];
long long a[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	bool af = 1, cf = 1;
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[n + 1 - i]) {
			af = 0;
		}
		if(c[i] != c[n + 1 - i]) {
			cf = 0;
		}
	}
	if(af && cf) {
		cout << 0 << endl;
		return 0;
	} else {
		cout << sum / 2 << endl;
	}
	return 0;
}
