#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , m , a[200010] , ans;
bool x[200010]; 
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 30; i >= 0; i--){
		int ad = 1 << i;
		int sum = 0;
		for (int j = 1; j <= n; j++){
			if (x[j]){
				continue;
			}
			if (a[j] & ad){
				sum++;
				//cout << j << " ";
			}
		} 
		if (sum >= m){
			ans += ad;
			for (int j = 1; j <= n; j++){
				if (!x[j] && !(a[j] & ad)){
					x[j] = 1;
					//cout << j << "<- ";
				}
			}
		}
		//cout << sum << " " << ad << " " << ans << "\n";
	}
	cout << ans;
	return 0;
}

