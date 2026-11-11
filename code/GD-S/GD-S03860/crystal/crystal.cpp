#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
long long a[N];

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long d = a[2] - a[1];
	bool able = 1; //是否可以用特殊性质 
	for (int i = 3; i <= n; i++) {
		if (d != a[i] - a[i - 1]) {
			able = 0;
			break;
		}
	}
	if (able) {
		long long delta = (1 + 4 * m / d);
		long long x = (-1 + ceil(sqrt(delta))) / 2;
		cout << x + 1;
		return 0; 
	}
	long long ret = 1;
	for (long long i = 2; i <= n; i++) {
		long long cost = 0;
		long long j = i - 1;
		while (j > 0) {
			cost += a[i] - a[j];
			if (cost > m) break;
			j--;
		}
//		cout << i << " " << j << "\n";
		ret = max(ret, i - j); 
	}
	cout << ret;
	return 0;
} 
