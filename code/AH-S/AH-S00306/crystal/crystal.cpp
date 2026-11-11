#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long n, m, a[N], cur, sum[N], ans = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	cur = 0;
	a[0] = a[1];
	for (int i = 0, j = 1; i <= n && j < n; ) {
		cur -= a[j] - a[i], i++;
		while (j < n && cur + (j - i + 1) * (a[j + 1] - a[j]) <= m)	cur += (j - i + 1) * (a[j + 1] - a[j]), j++;
		if (cur <= m)	ans = max(ans, (long long)(j - i + 1));
	}
	cout << ans << "\n";
	
	return 0;
}
