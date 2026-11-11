#include<bits/stdc++.h>
#define FOR(i , a , b) for(int i = (a) ; i <= (int)(b) ; ++ i) 
using namespace std ;
const int N = 3e5 + 10 ; 
int a[N]  ;
int ans[N] ;
int b[N] , p[N] , cnt = 1 ;
bool vis[N] ; 
signed main(){
	freopen("card.in","r",stdin) ; 
	freopen("card.out","w",stdout) ;  
	ios::sync_with_stdio(false) , cin.tie(0) ;  
	int n , m ; cin >> n >> m ; 
	FOR(i , 1 , n) cin >> a[i] ;
	//FOR(i , 1 , m) ans[i] = n ;
	FOR(i , 1 , n){
		memset(vis , 0 , sizeof vis) ;
		vector<int> v ; 
		FOR(j , i , n){
			if(vis[a[j]] == 1){
				while(v.back() != a[j]){
					vis[(int)v.back()] = 0 ;
					v.pop_back() ; 
				} 
				v.pop_back() ; 
			}
			vis[a[j]] = 1 ;
			v.push_back(a[j]) ;
		} 
//		for(int i = 0 ; i < (int)(v.size()) ; i ++){
//			cout << v[i] << " " ;
//		}
//		cout << "\n" ; 
		for(int i = 0 ; i < (int)(v.size()) ; i ++){
			ans[v[i]] ++ ;
		}
	//	FOR(i , 0 , cnt) cout << b[i] << " " ; 
//		FOR(i , 1 , cnt) ans[b[i]] ++ ; 
//		cout << "\n" ; 
	}
	FOR(i , 1  , m) cout << ans[i] << " " ; 
	return 0 ; 
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
10 1 0

*/
