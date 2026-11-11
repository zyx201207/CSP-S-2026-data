#include<bits/stdc++.h>
using namespace std;
int n , m ;
int a[200005] , maxn , ans ;
int dp[200005];

void solve1(){
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			ans = max(ans , a[i] & a[j]) ;
		}
	}
	cout << ans ;
	return;
}

void solve2(){
	for(int i = 1 ; i <= m ; i++){
		for(int j = n  ; j >= 1 ; j--){
			for(int k = 1 ; k < j ; k++){
				dp[j] = max(dp[j] , a[j] & a[k]);
			}
		}
	}
	cout << dp[n] ;
	return ;	
}

int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin.tie(0);
	cin >> n >> m ;
	if(n == 1){
		int t ;
		cin >> t ;
		cout << t ;
		return 0 ;
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(i == 1){
			ans = a[i];
		}
		maxn = max(maxn, a[i]);
		ans = ans & a[i];
	}
	if(m == 1){
		cout << maxn ;
		return 0 ;
	}
	if(m == n){
		cout << ans ;
		return 0 ;
	}
	ans = a[1] & a[2];
	if( m == 2 ){
		solve1();
		return 0 ;
	}
	solve2();
	return 0 ;
}


