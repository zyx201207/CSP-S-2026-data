#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5+10;
ll n,m,a[N],ans,sum,dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (m == 1){
		sort(a+1,a+n+1);
		cout << a[n];
	}else if (m == n){
		ans = a[1];
		for (int i = 2;i <= n;i++){
			ans = (a[i] & ans);
		}
		cout << ans;
	}else if (m == n-1){
		sort(a+1,a+n+1);
		ans = a[2];
		for (int i = 3;i <= n;i++){
			ans = (a[i] & ans);
		}
		cout <<ans; 
	}else if (m == 2){
		for (int i  =1;i <= n;i++){
			for (int j = i;j <= n;j++){
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
	}else{
		sort(a+1,a+n+1);
		ans = a[n];
		for (int i = n-1;i >= n-m;i--){
			ans = (ans & a[i]);
		}
		cout << ans;
	}
	return 0;
}
