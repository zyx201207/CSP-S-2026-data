#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, a[500005];
int l, r, Ans = 1;
long long Cost;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	l = 1, r = 1;
	while (r <= n) {
		++r;
		Cost += (a[r] - a[r - 1]) * (r - l);
		while (Cost > m) {
			Cost -= a[r] - a[l];
			++l;
		}
		Ans = max(Ans, r - l + 1);
	}
	cout << Ans;
	return 0;
}
//Oct31==Dec25?
// OK 100pts 14:39

