#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5 + 5 ;
int n, idx ; 
ll a[N], L, ans ; char c[N] ;
int main(){
	freopen("string.in", "r", stdin) ; 
	freopen("string.out", "w", stdout) ; 
	cin >> n ;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i] ;
		L += a[i] ;
	}
	ll mid = (L + 1) / 2, sum = 0 ;
	for(int i = 1, j = n; i <= n; i++){
		sum += a[i] ; 
		while(a[i] >= a[j] && a[i] && a[j]){
			if(c[i] != c[j]) ans += a[j] ;
			a[i] -= a[j], a[j] = 0, j-- ;
		}
		if(c[i] != c[j]){
			ans += a[i] ;
			a[j] -= a[i] ;
			a[i] = 0 ;
		}
		if(sum >= mid){
			idx = i ; break ;
		}
	}
//	 cout << ans << "\n" ;
	if(L % 2 == 1){
		int lt = mid - sum - 1 ;
		int rt = a[idx] - lt - 1 ;
		if(lt > rt && c[idx] != c[idx + 1]) ans += lt - rt ;
	}else{
		int lt = mid - sum ;
		int rt = a[idx] - lt ;
		if(lt > rt && c[idx] != c[idx + 1]) ans += lt - rt ;
	}
	cout << ans << "\n" ; 
	return 0 ;
}
