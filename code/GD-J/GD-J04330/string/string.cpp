#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], mx;
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		mx = max(a[i], mx);
	}
	if (mx * n <= 100000000) {
		string t = "";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i]; j++) {
				t += c[i];
			}
		}
		int len = t.size(), cnt = 0;
		for (int i = 0; i < len / 2; i++) {
			if (t[i] != t[len - i - 1]) {
				cnt++;
			}
		}
		cout << cnt;
	} 
	return 0;
}
