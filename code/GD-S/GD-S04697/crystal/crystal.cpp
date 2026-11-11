#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
long long n, m, maxn, l;
long long a[500005], sum;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	l = 1;
	for(int r = 1; r <= n; r++) {
		sum += a[r];
		while(sum + m + a[r] < a[r] * (r - l + 1 + 1) && l < r) {
			sum -= a[l++];
		}
		maxn = max(maxn, r - l + 1);
	}
	cout << maxn << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
