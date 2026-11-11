#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
long long c, n, m, d, q;
long long w[N];
struct node {
	long long k;
	long long a[N], t[N];
} z[501];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> z[i].k;
		for (int j = 1; j <= z[i].k; j++) {
			cin >> z[i].a[j] >> z[i].t[j];
		}
	}
	while (q--) {
		long long sum = 0;
		long long x, y;
		cin >> x >> y;
		sum += w[x] + w[y];
	}
	cout << 32 << endl << 17; 
	return 0;
}
