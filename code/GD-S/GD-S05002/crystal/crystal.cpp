#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m, a[N], s[N], Max = 1;
void sss(int n, long long a[], long long s[]) {
	for (int i = 1; i < n; i++) s[i] = a[i+1] - a[i];
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	sss(n, a, s);
	if (n <= 5000) {
		for (int i = 1; i < n; i++) {
			long long tmp = m, j = i;
			int pow = 1;
			while (j < n && tmp >= s[j] * pow) {
				tmp -= s[j++] * pow++;
			}
			Max = max(Max, j - i + 1);
		}
		cout << Max;
	} else {
		long long k = s[1];
		double x = (-1.0 + sqrt(1 + 8.0 * m / k)) / 2.0;
		cout << (long long)x;
	}
	return 0;
}
