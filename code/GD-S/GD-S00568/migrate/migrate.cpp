#include <bits/stdc++.h>
using namespace std;
#define int long long
unsigned long long c, t;
const int T = 1e5 + 10;
const int N = 2e6 + 10;
int n[T], d[T];
int x[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1;i <= t;i++){
		cin >> n[i] >> d[i];
		int ans = 0;
		for (int j = 1;j <= n[i];j++){
			cin >> x[j];
			if (x[j] % d[i] < d[i]){
				ans++;
			}
		}
		cout << ans % d[i] + 1 << '\n';
	}
	return 0;
}
