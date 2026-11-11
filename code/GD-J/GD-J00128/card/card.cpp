#include <bits/stdc++.h>
using namespace std;

int n, m, a[500010];

int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 1; j <= m; j++) {
		cout << rand() % (n + 1) << ' ';
	}
}
