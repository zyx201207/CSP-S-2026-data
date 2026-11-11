#include <bits/stdc++.h>
using namespace std ;
long long a[500114] , n , ans , b[500005];
long long m ; 
bool check(int x){
	
	long long sum ;
	for (int i = 1 ; i <= n - x + 1 ; i++){
		int sum = 0 ;
		for (int j = i ; j <= i + x - 1 ; j++){
			sum += b[i] - b[j] ;
		}
		if (sum <= m) return true ;
	}
	return false ;
}
int main()
{
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] ;
	}
	sort(a + 1 , a + n + 1) ;
	for (int i = 1 ; i <= n ; i++) b[i] = a[n - i + 1] ;
	int l = 1 , r = n ;
	while(l < r) {
		int mid = (l + r) / 2 ;
		if (check(mid)){
			l = mid + 1 ;
			ans = mid ;
		} 
		else r = mid - 1 ;
	}
	cout << ans ;
	return 0 ;
}
