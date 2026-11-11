#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
bool check(int k) {
	int l = 1, r = l + k - 1;
	long long sum = 0;
	for (int i=l; i<r; i++) sum += a[r] - a[i];
//	cout << "K:" << k << ' ' << "Psum:" << sum << "\n\n";
	for (; r<=n; l++,r++) {
		if (sum <= m) return true;
		sum -= a[r - 1] - a[l - 1];
		sum += (long long)k * (a[r] - a[r - 1]);
//		cout << l << ' ' << r << ' ' << sum << '\n';
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
long long check(int k) {
	long long cost = m, cnt = 0, i = k - 1;
	while (a[k] - a[i] <= cost && i >= 1) {
		cost -= a[k] - a[i];
		cnt++, i--;
	}
	return cnt + 1;
}
int main() {
	freopen("crystal2.in", "r", stdin);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1, r = n;
	long long ans = 0;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		long long tmp = check(mid);
		if (tmp >= ans) ans = tmp, l = mid;
		else r = mid - 1;
	}
	cout << l; 
	return 0;
}
*/
