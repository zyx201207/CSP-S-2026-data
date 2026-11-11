#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N], n, m; 
bool A() {
	for (int i = 1; i <= n; i++) {
		if (log2(a[i]+1) != (int)log2(a[i]+1))
			return false;
	}
	return true;
}
int B() {
	if (log2(n+1) != (int)log2(n+1))
		return 0;
	else 
		for (int i = 1; i <= n; i++)
			if (a[i] != i-1)
				return 0;
	return log2(n+1);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (A()) {
		int maxn = -1;
		for (int i = 1; i <= n; i++)
			maxn = max(maxn, a[i]);
		cout << maxn;
	} else if (B()) {
		int num = B()-1;
		if (num > m)
			cout << n-1;
	} 
	return 0;
}
