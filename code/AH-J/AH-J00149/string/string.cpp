#include <iostream>
#include <algorithm>
using namespace std;
int n, a[200005];
char c[200005];
long long L, r[200005];
long long Ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		r[i] = r[i - 1] + a[i];
		L += a[i];
	}
	for (int i = 1; i <= n && r[i - 1] + 1 <= L / 2; i++) {
		long long Tr = L - r[i - 1], Tl = L - r[i] + 1;
		int Ar = lower_bound(r + 1, r + n + 1, Tr) - r;
		int Al = lower_bound(r + 1, r + n + 1, Tl) - r;
		if (i > Al) continue ;
		for (int j = Al; j <= Ar; j++) {
			if (c[j] == c[i]) continue ;
			if (j == Al && j == Ar) Ans += Tr - Tl + 1;
			else if (j == Al) Ans += r[j] - Tl + 1;
			else if (j == Ar) Ans += Tr - r[j - 1];
			else Ans += r[j] - r[j - 1];
		}
	}
	cout << Ans;
	return 0;
}
/*
Trick||Treat!
*/
//OK 100pts

