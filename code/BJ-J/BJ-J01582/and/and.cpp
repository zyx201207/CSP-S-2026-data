#include<bits/stdc++.h>
using namespace std;
long long n, m, mx, ans1 = 2147483648, a[200010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out:, "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++;){
		cin >> a[i];
		ans1 &= a[i];
		mx = max(a[i], mx);
	}
	if(m == n){
		cout << ans1;
		return 0
	}
	if(m == 1){
		cout << mx;
		return 0;
	}
	mx = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			mx = max(mx, a[i] & a[j]);
		}
	}
	if(m == 2){
		cout << mx;
		return 0;
	}
	return 0;
}
