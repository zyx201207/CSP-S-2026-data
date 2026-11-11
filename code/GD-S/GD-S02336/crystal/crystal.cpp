#include <iostream>
#include <algorithm>

using namespace std;

const int N = 500010;

long long n, m;
long long a[N];

bool check(long long x) {
	long long res = 0;
	for (int i = 1; i <= n && a[i] <= x; ++i) {
		res += x - a[i];
	}
	return res <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	long long left = 1, right = n, ans = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check(a[mid])) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	
	cout << ans;
	
	return 0;
} 
