#include <bits/stdc++.h>
//#define int long long
using namespace std ;
int n ,  m , ans = 0x3f3f3f3f ;
priority_queue <int , vector <int> , greater <int>> q ;
signed main() {
	//freopen("and.in" , "r" , stdin) ;
	//freopen("and.out" , "w" , stdout) ;
	cin.tie(nullptr) -> ios :: sync_with_stdio(false) ;
	cin >> n >> m ;
	for(int i = 1 , a ; i <= n ; i ++) {
		cin >> a ;
		q.push(a) ;
	}
	while(q.size() > m) q.pop() ;
	for(int i = 1 ; i <= m ; i ++) {
		int u = q.top() ;
		q.pop() ;
		ans &= u ;
	}
	cout << ans << "\n" ;
	return 0 ;
}

