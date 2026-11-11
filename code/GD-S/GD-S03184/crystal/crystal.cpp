#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
int n;
long long m, a[MAX];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + ((r - l) >> 1);
		int L = 1, R = 0;
		unsigned long long sum = 0;
		bool flag = false;
		while (R <= n) {
			if (R - L + 1 == mid) {
				long long add = mid * a[R] - sum;
				if (add <= m) {
					flag = true;
					break;
				}
				sum -= a[L++];
			}
			else {
				sum += a[++R];
			}
		}
		if (flag) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l - 1;
	return 0;
} 
