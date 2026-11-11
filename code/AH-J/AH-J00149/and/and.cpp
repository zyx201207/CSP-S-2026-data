#include <iostream>
using namespace std;
int n, m;
int a[200005];
bool b[200005];
int Ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], b[i] = 1;
	for (int i = 30; ~i; i--) {
		int Cnt1 = 0;
		for (int j = 1; j <= n; j++) if (b[j] && (a[j] >> i & 1)) ++Cnt1;
		if (Cnt1 >= m) {
			Ans += (1 << i);
			for (int j = 1; j <= n; j++) if (b[j] && !(a[j] >> i & 1)) b[j] = 0;
		}
	}
	cout << Ans;
	return 0;
}
/*
Trick||Treat!
*/
//OK 100pts

