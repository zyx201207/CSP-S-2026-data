#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 2e5 + 10;
int n, a[N];
char c[N];

int main() {
  	freopen("string.in", "r", stdin);
  	freopen("string.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	ll l = 0, r = n + 1, f1 = 0, f2 = 0, ans = 0; 
	while (l < r) {
//		cout << l << " " << r << endl;
//		cout << f1 << " " << f2 << endl;
//		cout << ans << endl;
		if (f1 == 0) f1 = a[++l];
		if (f2 == 0) f2 = a[--r];
		if (!(l < r)) break;
		int k = min(f1, f2);
		f1 -= k, f2 -= k;
		if (c[l] != c[r]) ans += k;
//		cout << "------\n";
	}
	cout << ans << endl;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
