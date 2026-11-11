#include<bits/stdc++.h>

using namespace std;
#define int long long
int c,T,a[200005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--) {
		int n,d;cin >> n >> d;
		for(int i = 1;i <= n; i++) cin >> a[i];
		
		int ans = 0;
		for(int k = 1;k <= n; k++) {
			int f[200005];
			//for(int i = 1;i <= n; i++) f[i] = 0;
			f[k] = 1;
			for(int i = k + 1;i <= n; i++) {
				for(int j = i;j >= max(k,i - d);j--) {
					f[j] += f[i];
				}
			}
			
			for(int i = 1;i <= n; i++) {
				//cout << f[i] << " ";
				if(f[i] == 2) ans++;
			}
			//cout << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
} 
