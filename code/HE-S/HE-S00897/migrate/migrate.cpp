#include<bits/stdc++.h>
using namespace std; 
long long n , m;
long long abcd , T;
long long a[2000005];
int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> abcd >> T;
	while(T--) {
		cin >> n >> m;
		for(long long i = 1;i <= n;i++) cin >> a[i];
		if(m >= 3 * a[2] - a[1]) {
			cout << 0 << endl;
		}
		else if(m >= 2 * a[2] - a[1]){
			long long ans = 0;
			for(int i = 1;i <= n;i++) {
				if(i % 2 == 0) ans++;
			}
			cout << ans << endl;
		}
	}
	
	
	return 0;
}
