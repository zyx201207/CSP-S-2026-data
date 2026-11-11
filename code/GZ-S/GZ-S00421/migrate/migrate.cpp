//GZ-S00421 遵义第十二中学 陈俊熙 
#include <bits/stdc++.h>
using namespace std;

const long long N = 2e6 + 10;
int c, t;
long long a[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		long long d1 = a[2] - a[1];
		
		if (d < d1 * 2) {
			cout << 0 << endl;
			break;
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				long long l = (a[j] - a[i]) % d == 0 ? (a[j] - a[i]) / d : (a[j] - a[i]) / d + 1;
				if ((j - i + 1) % l == 0 && l != 1) ans++;
			}
			
		}
		
		cout << ans << endl;
	}
	return 0; 
}
