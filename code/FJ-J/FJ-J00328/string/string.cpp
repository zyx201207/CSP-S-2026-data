#include <iostream>
using namespace std;
int main() {
	freopen("string.in", "r", stdin); freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; long long ans = 0, ds = 0; cin >> n; string s = "";
	for (int i = 1; i <= n; i ++) {
		int a; char c; cin >> a >> c;
		for (int i = 1; i <= a; i ++) s += c;
		ds += a;
	}
	for (int i = 0; i <= ds / 2 - 1; i ++) if (s[i] != s[ds - i - 1]) { ans ++; }
	cout << ans;
	return 0;
}
