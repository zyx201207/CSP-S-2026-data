#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "W", stdout);
	int n, m;
	cin >> n >> m;
	int a[200005], b[2000005];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			b[i] = a[i] & a[j] & a[j + 1];
		}
	}
	sort(b + 1, b + 1 + n);
	cout << b[n];
	return 0;
}
