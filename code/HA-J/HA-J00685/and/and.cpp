#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];
int n, m;

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int maxn = 0;
	for (int i = n - m + 1; i >= 1; i--) {
		int andd = a[i];
		for (int j = m; j >= 2; j--) andd = andd & a[i + j - 1];
		maxn = max(maxn, andd);
	}
	cout << maxn << "\n";
	return 0;
}

