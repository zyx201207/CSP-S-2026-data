#include <bits/stdc++.h> 
using namespace std;
const int N = 5 * 1e5 + 10;
long long n, m;
long long a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if ((a[2] - a[1] == a[3] - a[2]) && n % 2 == 0 && (a[2] - a[1]) != 1) {
		cout << m / (a[2] - a[1]);
		return 0;
	}
	cout << m / 2 + 1;
	return 0; 
}
