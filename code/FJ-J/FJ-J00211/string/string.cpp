#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

constexpr int N = 2e5 + 5;
long a[N];
char c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
	}
	
	long long ans = 0;
	int l = 1;
	int r = n;
	
	while (l < r) {
		if (a[l] == a[r]) {
			ans += (c[l] != c[r]) ? a[r] : 0;
			++l; --r;
		}
		else if (a[l] > a[r]) {
			ans += (c[l] != c[r]) ? a[r] : 0;
			a[l] -= a[r];
			--r;
		} else { // a[l] < a[r]
			ans += (c[l] != c[r]) ? a[l] : 0;
			a[r] -= a[l];
			++l;
		}
	}
	
	cout << ans << endl;
	return 0;
}

