#include <iostream>
#include <algorithm>
using namespace std;

long long n, a[200005];
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> c[i];
	
	long long l = 1, r = n, ans = 0;
	while (l <= r) {
		if (c[l] != c[r]) ans += min(a[l], a[r]);
		
		if (a[l] < a[r]) {
			a[r] -= a[l];
			a[l] = 0;
			l++;
		}
		else if (a[l] > a[r]) {
			a[l] -= a[r];
			a[r] = 0;
			r--;
		}
		else {
			a[l] = a[r] = 0;
			l++; r--;
		}
	}
	
	cout << ans;
	
	return 0;
}
