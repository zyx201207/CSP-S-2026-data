#include <bits/stdc++.h>
using namespace std; 
const int N = 5e5 + 10;
int n, m, a[N], maxn[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		cout << maxn[i] << ' ';
	}
	return 0;
} 
