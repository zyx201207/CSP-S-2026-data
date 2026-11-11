#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5 + 5 ;
int n, m, idx ; ll ans ;
ll a[N] ;
set<ll> g[32] ;
int main(){
	freopen("and.in", "r", stdin) ;
	freopen("and.out", "w", stdout) ;
	cin >> n >> m ;
	for(int i = 1; i <= n; i++) cin >> a[i] ;
	for(int i = 1; i <= n; i++){
		for(int j = 30; j >= 0; j--){
			int p = ((a[i] >> j) & 1) ;
			if(p) g[j].insert(a[i]) ;
		}
	}
	for(int i = 30; i >= 0; i--)
		if(g[i].size() >= m){
			idx = i ; ans += 1 << i ;
			break ;
		}
	for(int j = idx - 1; j >= 0 ; j--){
		int p = 0 ;
		if(g[idx].size() < m) break ;
		for(auto it = g[idx].begin(); it != g[idx].end(); it++)
			p += ((*it) >> j) & 1 ;
		if(p >= m){
			auto it = g[idx].begin() ;
			while(it != g[idx].end()){
				int tmp = *it ;
				if(((tmp >> j) & 1) == 0) g[idx].erase(it) ;
				it++ ;
			}
			ans += 1 << j ;
		}
	}
	cout << ans << "\n" ;
	return 0 ;
}
