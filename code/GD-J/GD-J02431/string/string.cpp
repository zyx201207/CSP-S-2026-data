#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

long long ans;
long long a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
	}
	
	int left = 1, right = n;
	
	while (left < right) {
		if (c[left] == c[right]) {
			if (a[left] == a[right]) {
				++left;
				--right;
			} else if (a[left] > a[right]) {
				a[left] -= a[right];
				--right;
			} else {
				a[right] -= a[left];
				++left;
			}
		} else {
			if (a[left] == a[right]) {
				ans += a[left];
				++left;
				--right;
			} else if (a[left] > a[right]) {
				a[left] -= a[right];
				ans += a[right];
				--right;
			} else {
				a[right] -= a[left];
				ans += a[left];
				++left;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
