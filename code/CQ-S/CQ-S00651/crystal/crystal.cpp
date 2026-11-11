#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n;
ll m;
ll a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, res = 0;
		while(l <= r) {
			int mid = l + r >> 1;
			if(m >= a[i] * (i - 1 - mid + 1) - (s[i - 1] - s[mid - 1])) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - res + 1);
	}
	
	cout << ans << endl;
	
	return 0;
}
