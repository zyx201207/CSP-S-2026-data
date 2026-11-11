#include <bits/stdc++.h>
#define qwq ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
char c[N];
int cnt;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	qwq;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for (int i = 1, j = n; i <= n and j >= 1; ) {
		if (i >= j) break ;
		int tmp = min(a[i], a[j]);
		if (c[i] == c[j]) {
			a[i] -= tmp;
			a[j] -= tmp;
		} 
		else {
			cnt += tmp;
			a[i] -= tmp;
			a[j] -= tmp;
		}
		if (a[i] == 0) i++;
		if (a[j] == 0) j--;
	}
	cout << cnt << "\n";
	return 0;
} 
