#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
int a[maxn], b[maxn];

bool cmp (int x, int y) {
	return x > y;
}

int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	
	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort (a, a + n, cmp);
	
	long long ans = 0;
	for (int i = 0, jj; i < m; i++) {
		b[jj] = a[i];
		jj++;
	}
	for (int i = 1; i < jj; i++) {
		b[i + 1] = b[i] and a[i + 1];
	}
	cout << ans << endl;
	return 0;
}
