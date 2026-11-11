#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
bool cmp(int a, int b){
	return a > b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	int x = a[1];
	for (int i = 2; i <= n; i ++){
		cin >> a[i];
		x &= a[i];
	}
	if (m == n){
		cout << x << "\n";
		return 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	if (m == 1){
		cout << a[1] << "\n";
		return 0;
	}
	if (m == 2 && n <= 2000){
		int ans = 0;
		for (int i = 1; i <= n; i ++){
			for (int j = i + 1; j <= n; j ++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << "\n";
		return 0;
	}
	for (int i = 1; i <= min(n, m); i ++){
		for (int j = 30; j >= 0; j --){
			if (a[i] == 1 << j){
				m ++;
			}
		}
	}
	m = min(m, n);
	cout << a[m];
	return 0;
}
