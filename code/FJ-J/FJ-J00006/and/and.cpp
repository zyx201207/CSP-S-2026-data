#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n, m, a[N], ans;
void Sub1() {
	for (int S = 0; S < (1 << n); S++) {
		int cnt = 0, now = (1 << n) - 1;
		for (int i = 1; i <= n; i++) {
			if (!(S & (1 << (i - 1)))) continue;
			cnt++;
			now &= a[i];
		}
		if (cnt == m) ans = max(ans, now);
	}
	cout << ans << '\n';
}
void Sub2() {
	sort(a + 1, a + n + 1, greater<int>());
	cout << a[1] << '\n';
}
void Sub3() {
	ans = a[1];
	for (int i = 1; i <= n; i++) ans &= a[i];
	cout << ans << '\n';
}
void Sub4() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) ans = max(ans, a[i] & a[j]);
	cout << ans << '\n';
}
void Sub5() {
	int res = a[1];
	vector<int> v[30];
	for (int i = 1; i <= n; i++) {
		int k = a[i];
		for (int j = 0; j <= 29; j++) {
			if (!(k & 1)) v[j].emplace_back(i);
			k >>= 1;
		}
		if (i > 1) res &= a[i];
	}
	for (int i = 1; i <= n; i++) {
		int now = res;
		for (int j = 0; j <= 29; j++) 
			if (v[j].size() == 1) now |= (1 << j);
		ans = max(ans, now);
	}
	cout << ans << '\n';	
}
void Sub6() {
	sort(a + 1, a + n + 1, greater<int>());
	ans = a[1];
	for (int i = 2; i <= m; i++) ans &= a[i];
	cout << ans << '\n';
}
bool checkA() {
	int pow[30] = {1};
	for (int i = 1; i < 30; i++) pow[i] = pow[i - 1] * 2;
	for (int i = 1; i <= n; i++) {
		int k = a[i];
		bool flag = false;	
		for (int j = 29; j >= 0; j--)
			if (k == pow[j] - 1) {
				flag = true;
				break;
			}
		if (!flag) return false;
	}
	return true;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20) Sub1();
	else if (m == 1) Sub2();
	else if (m == n) Sub3();
	else if (m == 2) Sub4();
	else if (m == n - 1) Sub5();
	else Sub6();
	fclose(stdin);
	fclose(stdout);
} 
