#include <bits/stdc++.h>
#define int long long
using namespace std ;
using ll = long long ;
const int N = 5e5 + 5 , M = 3e5 + 5 ;
int n , m , a[N] , ans[M] ;
signed main() {
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	cin.tie(nullptr) -> ios :: sync_with_stdio(false) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] ;
	for(int i = 1 ; i <= n ; i ++) {
		//vector <int> v ;
		int b[m + 1] ;
		fill(b , b + m + 1 , 0) ;
		for(int j = i ; j <= n ; j ++) {
			if(b[a[j]]) {
				for(int k = a[j] ; k <= m ; k ++) b[k] = 0 ;
				b[a[j]] ++ ;
			}else b[a[j]] ++ ;
			//if(v.find(a[j])) v.clear();
			//else v.push_back(a[j]) ;
		}
		for(int i = 1 ; i <= m ; i ++) ans[i] += (b[i]) ;
		//for(auto e : v) ans[e] ++ ;
	}
	for(int i = 1 ; i <= m ; i ++) cout << ans[i] << " " ;
	return 0 ;
}

