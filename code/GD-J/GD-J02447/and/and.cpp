#include <bits/stdc++.h>

using namespace std;

int n, m;
const int maxn = 2e5 + 1;
int a[maxn];
int ans = -0x3f3f3f3f;
void dfs(int pos, int num, int val) {
	if (num == m) {
		ans = max(ans, val);
		return;
	}
	if (pos > n) return;
	if (val == 0) {
		dfs(pos + 1, num + 1, a[pos]);
	}
	dfs(pos + 1, num + 1, val & a[pos]);
	dfs(pos + 1, num, val);
}
int power2[31];
set<long long> st;
void init() {
	power2[0] = 1;
	for (int i = 1; i <= 30; i++) {
		power2[i] = power2[i - 1] * 2;
		st.insert(power2[i]);
	}
}
bool propertyA() {
	for (int i = 1; i <= n; i++) {
		if (!st.count(a[i] + 1)) return false;
	}
	sort(a + 1, a + n + 1, greater<int>());
	ans = a[m];
	return true;
}
bool propertyB() {
	if (!st.count(n)) return false;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i - 1) return false;
	}
	int k;
	for (int i = 1; i <= 30; i++) {
		if (power2[i] == n) {
			k = i;
			break;
		}
	}
	if (k - m + 1 >= 1) {
		ans = power2[k - m + 1]; 
	}
	return true;
}
int num[4];
bool propertyC() {
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 4) return false;
		num[a[i]]++;
	}
	if (num[3] >= m) cout << 3 << '\n';
	else if (num[2] + num[3] >= m) cout << 2 << '\n';
	else if (num[1] + num[3] >= m) cout << 1 << '\n';
	else cout << 0 << '\n';
	return true;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	init();
	if (propertyA()) {
		cout << ans << '\n';
		return 0;	
	}
	if (propertyB()) {
		cout << ans << '\n';
		return 0;
	}
	if (propertyC()) {
		return 0;
	}
	dfs(1, 0, 0x1fffffff);
	cout << ans << '\n';
}
