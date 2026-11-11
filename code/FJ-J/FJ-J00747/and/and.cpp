#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200010];
bool cmp(long long a, long long b){
	if (a == b) return a = b;
	return a > b;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	long long ans = a[1];
	for (int i = 2;i <= m;i++) ans = (ans & a[i]);
	cout << ans;
	return 0;
}
