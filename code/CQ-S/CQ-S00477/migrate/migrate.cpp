#include<bits/stdc++.h>
#define ll long long
using namespace std; 
int C, T;
int n, d, a[2000006];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w" , stdout);
	cin >> C >> T;
	while(T--){
		cin >> n >> d;
		int ans = 0;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i < n; ++i) {
			int k = a[i] + d, k1 = a[i] - 1 + 2 * d, w = a[i] + d - 1;
			int s = lower_bound(a + 1, a + n + 1, k) - a;
			int s1 = lower_bound(a + 1, a + n + 1, k1) - a;
			int s2 = lower_bound(a +1, a + n + 1, w) - a;
			if(a[s1] == a[i] - 1 + 2 * d && a[s] == a[i] + d && a[s2] == a[i] + d - 1) ans ++;
		}
		cout << ans << "\n";
	}
	return 0;
}

