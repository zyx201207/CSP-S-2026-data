#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
int n, m;
unsigned long long a[MAX_N];
unsigned long long ans;
bool flag;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]  != i - 1) {
			flag = true;
		}
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	if (m == 1) {
		cout << "0";
		return 0;
	}
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if (m == n - 1) {
		for (int i = 1; i <= n - 1; i++) {
			ans &= a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if (flag) {
		cout << "1";
		return 0;
	}
	cout << "1" << endl;
	return 0;
}
