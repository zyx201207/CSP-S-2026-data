#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int n, m;
ll a[N], s, l;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	s = a[1], l = a[1];
	for (int i = 2; i <= n; i++) {
		s = max(s, a[i]);
		l = l & a[i];
	}
	if (m == 1) {
		cout << s << '\n';
	}  if (m == n) {
		cout << l << '\n';
	}
	return 0;
}
