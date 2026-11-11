#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 7;
int n, m, ans; 
int a[maxn];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + n + 1);
	ans = a[n];
	for(int i = n - 1; i > n - m; i--){
		ans = ans & a[i];
	}
	cout << ans << endl;
	return 0;
}
