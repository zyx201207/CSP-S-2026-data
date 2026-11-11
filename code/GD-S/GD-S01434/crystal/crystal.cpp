#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

int n;
long long m, a[N + 10];

int main() {
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	int ans = 1; long long sum = 0;
	for (int i = 2, j = 1; i <= n; ++i) {
		sum += (a[i] - a[i - 1]) * (long long)(i - j);
		while (sum > m) {sum -= a[i] - a[j]; ++j;}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	
	return 0;
}

// chennie bless me

/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/
