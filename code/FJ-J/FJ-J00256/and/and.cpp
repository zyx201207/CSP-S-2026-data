#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010], mx = -1; 
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if(m == 1){
		cout << mx;
	}
	else if(m == n){
		int ans = a[1];
		for(int i = 2; i <= n; i++){
			ans = (a[i] && ans);
		}
		cout << ans;
	}
	else if(m == 2){
		int mxx = -1;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				int wc = (a[i] && a[j]);
				mxx = max(mxx, wc);
			}
		}
		cout << mxx;
	}
	else if(m == (n - 1)){
		int ans = a[1], mxxx = -1;
		for(int i = 2; i <= n; i++){
			ans = (a[i] && ans);
		}
		for(int i = 1; i <= n; i++){
			int sm = (ans || a[i]);
			mxxx = max(mxxx, sm);
		}
		cout << mxxx;
	}
	return 0;
}
