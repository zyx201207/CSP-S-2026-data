#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 10;
int n;
LL d;
LL a[N];
LL cha[N];
LL f[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while(T --) {//多测清空了，你气不气？ ‘_’ 
		memset(a, 0, sizeof a);
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		long long ans = 0;

		if(n <= 10) {
			for(int i = 1; i < n; i ++) {
			
				for(int j = i + 2; j <= n; j ++) {
				
					if((a[j] - a[i]) % d != 0 && (a[j] - a[i] + d - 1) / d > 1) {
					
						ans ++;
					}
				}
			}
			cout << ans << '\n';
		}
		else {
		
			for(int i = 1; i < n; i ++) {
			
				for(int j = i + 2; j <= n; j ++) {
					
					if((a[j] - a[i]) % d != 0 && (a[j] - a[i] + d - 1) / d > 1) {
						f[i] += f[j] + 1;
					}
				}
			}
			cout << f[n] << '\n';
		}
	}
	return 0;
}
