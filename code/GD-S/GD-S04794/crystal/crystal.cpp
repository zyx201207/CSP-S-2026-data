#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5e5 + 3;

int n, ans;
long long a[maxn], s[maxn], m;

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		s[i] = a[i] + s[i - 1];
	}
	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= n && 
			(j - i) * a[i] - (s[j] - s[i]) <= m) j++;
		ans = max(ans, j - i);
		// cerr << j - i << ' ';
	}
	cout << ans << '\n';

	return 0;
}