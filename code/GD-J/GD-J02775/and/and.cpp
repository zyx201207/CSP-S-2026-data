#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n, m, mx;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	vector<ull>a(n);
	for (auto & i : a) cin >> i;
	if (m == 1)
		cout << *max_element(a.begin(), a.end());
	if (m == 2)
		for (ull i = 0; i < n - 1; i++) {
			for (ull j = i + 1; j < n; j++) {
				mx = max(mx, a[i] & a[j]);
			}
		}
	if (m == n)
		for (int i = 1; i < n; i++) {
			a[i] &= a[i - 1];
			mx = a[i];
		}
	cout << mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
