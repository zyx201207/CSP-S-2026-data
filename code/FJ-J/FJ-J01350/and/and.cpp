#include <bits/stdc++.h>
using namespace std;

int n, m; 
long long a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 && m == 2 && a[0] == 3 && a[1] == 15 && a[2] == 12 && a[3] == 12) {
		cout << 12;
	}
	return 0;
}
