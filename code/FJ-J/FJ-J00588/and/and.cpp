#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans[200005];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++) {
		cin >> a[i];
	}
	ans[0] = INT_MAX;
	for(int i = 0 ; i < n ; i ++) {
		for(int j = m + 2 ; j >= 0  ; j --) {
			ans[j + 1] = max(ans[j] & a[i] , ans[j + 1]);
		}
	}
//	for(int i = 0 ; i <= n ; i ++) {
//		cout << ans[i] << " ";
//	}
	cout << ans[m];
	return 0;
}
