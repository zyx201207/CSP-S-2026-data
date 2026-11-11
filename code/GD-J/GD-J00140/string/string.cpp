#include<iostream>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, ans, a[N]; string str;
char c[N];
void sol(string x) {
	int l = 0, r = x.length() - 1;
	while (l <= r) {
		if (x[l] != x[r]) ans++;
		l++, r--;
	}
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n; char tmp; bool flag = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		if (i == 0) tmp = c[i];
		if (i > 0 && c[i] != tmp) flag = false;
	}
	if (flag) {
		cout << 0 << endl;
		exit(0);
	}
	for (int i = 0; i < n; i++)
		while (a[i]--) str.push_back(c[i]);
	sol(str); cout << ans << endl;
	return 0;
}
