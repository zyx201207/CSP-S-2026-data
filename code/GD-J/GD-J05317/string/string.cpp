#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200010;
int n, a[N], c[N], ans;
char cc;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> cc, c[i] = cc;
	int l = 1, r = n, op = 0;
	while (l < r){
		if (c[l] != c[r])
			ans += min(a[l], a[r]);
		op = a[r] > a[l],
		(op ? a[r] : a[l]) = abs(a[l] - a[r]),
		(op ? (l ++) : (r --));
	}return cout << ans, 0;
}
//freopen("string.in", "r", stdin);
//freopen("string.out", "w", stdout);
