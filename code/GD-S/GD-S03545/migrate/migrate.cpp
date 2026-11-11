#include <bits/stdc++.h>
using namespace std;
long long a[2010000];
int nxt[2010000]; 
long long num[2010000];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--){
		long long n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = n; i >= 1; i--){
			int p = upper_bound(a + i, a + n + 1, a[i] + d) - a - 1;
			nxt[i] = p; 
		}
		long long ans = 0;
		nxt[0] = 1;
		for (int i = n; i >= 1; i--){
			if (nxt[i] == i + 1){
				ans += num[i + 1];
				num[i] = num[i + 1];
			}
//			cout << i << ' ' << nxt[i] << '\n';
			if (nxt[i] == i || nxt[i] == i + 1){
				continue;
			}
			ans += nxt[nxt[i] - 1] - nxt[nxt[i] - 2];
			num[i] += nxt[nxt[i] - 1] - nxt[nxt[i] - 2];
//			cout << num[i] << '\n'; 
		}
		cout << ans << '\n';
		for (int i = 0; i <= n; i++){
			a[i] = 0;
			nxt[i] = 0;
			num[i] = 0;
		}
	}
	return 0;
}
/*
1 1
10 3
0 3 6 7 8 9 10 11 14 17
1 1 1 0 0 0 0  0  0  0
*/
