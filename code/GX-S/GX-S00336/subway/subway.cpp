#include<bits/stdc++.h>
using namespace std; 
#define int long long
const int N = 5e5 + 10 , M = 505 ; 
int c , n , m , d , q , w[N] ;
vector<pair<int , int>> s[N] ;
int D[M][M] ;
signed main() {
    freopen("subway.in","r",stdin) ;
    freopen("subway.out","w",stdout) ;
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
    cin >> c >> m >> n >> d >> q ;
    for(int i = 1 ; i <= n ; i ++ ) cin >> w[i] ;
    memset(D , 0x3f,sizeof D) ;
    for(int i = 1 ; i <= m ; i ++ ) {
        D[i][i] = 0 ;
        int k ; cin >> k ;
        while( k -- ) {int x , t ; cin >> x >> t ; s[x].push_back({i , t}) ;} 
    }
    for(int i = 1 ; i <= n ; i ++ ) {
        for(auto [it , x] : s[i] ) 
            for(auto [it2 , x2] : s[i] ) 
                D[it][it2] = min(D[it][it2] , x + x2 ) ;  
    }
    for(int k = 1 ; k <= m ; k ++ ) {
        for(int i = 1 ; i <= m ; i ++ ) 
            for(int j = 1 ; j <= m ; j ++ ) 
                D[i][j] = min(D[i][j] , D[i][k] + D[k][j] )  ;
    }
    while(q -- ) {
        int x , y ;
        cin >> x >> y ;
        int ans = 1e18 ;
        for(auto [ix , wx] : s[x] ) 
            for(auto [iy , wy] : s[y] ) 
                ans = min(ans ,wx + wy + D[ix][iy] ) ;
        cout << ans + w[x] + w[y] << '\n' ;
    }
    return 0 ;
}