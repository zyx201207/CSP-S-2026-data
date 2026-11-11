#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int m, n;
int ans = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	ans = a[1];
	for(int i = 2; i <= m; i++) ans &= a[i];
	cout << ans;
	return 0;
}
