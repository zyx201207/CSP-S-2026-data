#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
long long a[N];
int n;
long long m;
bool check(int mid) {
	LL minn = 4e18;
	for (int i = 1; i <= n - mid + 1; i ++) {
		LL sum = 0;
		for (int j = i; j <= i + mid - 1; j ++) {
			sum += a[i + mid - 1] - a[j];
		}
		minn = min(sum, minn);
	}
	if (minn > m) return false;
	else return true;
}
bool check1(int mid) {
	LL c = a[2] - a[1];
	LL sum = 0; 
	for (int i = 1; i < mid; i ++) {
		sum += (LL)i * c;
	}
	if (sum > m) return false;
	return true;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	bool A = true;
	for (int i = 2; i < n; i ++) {
		if (a[i] - a[i - 1] != a[i + 1] - a[i]) A = false;
	}
	sort(a + 1, a + n + 1);
	if (A) {
		int l = 1, r = n;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (check1(mid)) l = mid;
			else r = mid - 1;
		}
		cout << r;
		return 0;
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << r;
	return 0;
} 
