#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int main() {
	freopen("subway3.in", "r", stdin);
	int n = 0;
	while (cin >> a[++n]);
	freopen("test.txt", "r", stdin);
	for (int i=1; i<=n; i++) cin >> b[i];
	for (int i=1; i<=n; i++) {
		cout << a[i] << ' ' << b[i] << '\n';
	}
	cout << "YeS";
	return 0;
}
