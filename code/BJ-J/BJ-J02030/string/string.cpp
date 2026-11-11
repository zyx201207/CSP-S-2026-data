#include <bits/stdc++.h>
using namespace std;
long long n, a, num = 0, k = 0, cnt = 0;
char c;
string h;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a >> c;
		for (int j = 0; j < a; j ++) {
			h [j + k] = c;
		}
		k += a;
	}
	for (size_t i = 0; i <= h.size() / 2; i ++) {
		if (h[i] != h[h.size() - i - 1]) {
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}