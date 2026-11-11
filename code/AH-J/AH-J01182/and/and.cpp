#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2005];
signed main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (n == m) {
		int ans = a[1];
		for (int i = 2;i <= n;i++){
			ans &= a[i];
		} 
		cout << ans;
		return 0;
	}
	if (m == 1){
		int mx = -1;
		for (int i = 1;i <= n;i++){
			mx = max(mx,a[i]); 
		}
		cout << mx;
		return 0;
	}
	if (n <= 20){
		int mx = -1;
		for (int i = 0;i < (1 << (n+1));i++){
			int cnt = 0,ans = 0;
			for (int j = 1;j <= n;j++){
				if (i & (1 << j)) {
					cnt++;
					if (cnt == 1) ans = a[j];
					else {
						ans &= a[j];
					}
				}
			}
			if (cnt == m) mx = max(mx,ans);
		}
		cout << mx;
	}
	return 0;
}
