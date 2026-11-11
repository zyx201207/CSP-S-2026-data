#include <bits/stdc++.h>
using namespace std;

int n, m, a[200010], maxn;

int main() {
	//freopen("and1.in", "r", stdin);
	//freopen("and1.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) scanf("%d", a[i]), maxn = max(maxn, a[i]);
	sort(a + 1, a + n + 1);
	if(m == 1) cout << a[n];
	if(m == 2) cout << (a[n] & a[n - 1]);
	return 0;
}
