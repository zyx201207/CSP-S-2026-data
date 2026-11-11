#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005];

int main() {
	freopen("crystal.in",  "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int maxn = INT_MIN;
	for (int i = 1; i < n; i++) {
		int sum = 0;
		for (int j = i+1; j <= n; j++) {
			if (sum + (a[j]-a[j-1])*(j-i) > m) break;
			else {
				sum += (a[j]-a[j-1])*(j-i);
				maxn = max(maxn, j-i+1);
			}
		}
	}
	cout << maxn;
}
