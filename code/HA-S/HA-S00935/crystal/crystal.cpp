#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500001];
int k[500001], s[500001];
int ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1); 
	if (n <= 5000){
		for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			k[j] = a[i] - a[i - j + 1];
			s[j] = s[j - 1] + max(k[j], 0ll);
			if (s[j] <= m)
				ans = j;
			}
		}
	}
	else{
		int deltaA = a[2] - a[1];
		ans = 0;
		for (int i = 1; i <= n; i++){
			ans += i * deltaA;
			if (ans <= m)
				ans = i;
		}
	}
	cout << ans;
	return 0;
}

