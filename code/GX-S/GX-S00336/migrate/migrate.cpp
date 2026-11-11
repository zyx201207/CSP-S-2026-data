#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10 ;
int n , d , a[N] , nxt[N] , pre[N] ;
bool ok[N] ;
int zz[N][2] , S[N] , jp[N] , gg[N] ;
void solve() {
    cin >> n >> d ;
    for(int i = 1 ; i <= n ; i ++ ) cin >> a[i] , jp[i] = gg[i] = S[i] = 0 ;
    // if(n > 1000) {cout << -1 << '\n' ; return ;}
    for(int i = 1 , j = 1 ; i <= n ; i ++ ) {
        while(j < n && a[j + 1] - a[i] <= d ) ++ j ;
        nxt[i] = j ;
    }
    for(int i = n , j = n ; i ; i -- ) {
        while(j > 1 && a[i] - a[j - 1] <= d ) -- j ;
        pre[i] = j ;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        ok[i] = (!(nxt[i] - i > 1 && nxt[nxt[i] - 1] == nxt[nxt[i]] && pre[nxt[i] - 1] < i)) & (!(nxt[i] - i > 2 && nxt[nxt[i] - 2] == nxt[nxt[i]])) & (nxt[i] != i );
        zz[i][0] = zz[i][1] = 0 ;
        if(nxt[i] != i && nxt[nxt[i]] != i ) {
            for(int s : {0 , 1} ) {
                zz[i][s] = 0 ;
                int now = nxt[i] ;
                if(i == now - 1 ) zz[i][s] += (s == 1) * (nxt[now] - now) ;
                else {
                    zz[i][s] += ( s == 1 ) * (nxt[now] - nxt[now - 1]) ;
                    int o = s ;
                    s -= nxt[now - 1] == nxt[now] ;
                    // cout << i << ' ' << s << '\n' ;
                    if(!s && pre[now - 1] == i ) zz[i][o] += (nxt[now - 1] - (now - i > 2 ? nxt[now - 2] : now) ) ;
                    s += nxt[now - 1] == nxt[now] ;
                }
            }
        }
        S[i] = nxt[i] - i > 1 ? nxt[nxt[i] - 1] == nxt[nxt[i]] : 0 ;
    } 
    for(int i = n ; i ; -- i ) {
        if(S[i]) jp[i] = i ;
        else jp[i] = jp[nxt[i]] ;
        for(int o = 0 ;o < 2 ; o ++ ) zz[i][o] += zz[nxt[i]][o] ;
        if(!ok[i]) gg[i] = i ;
        else gg[i] = gg[nxt[i]] ;
    }
    zz[n + 1][0] = zz[n + 1][1] = 0 ;
    int ans = 0 ;
    for(int i = 1 ; i <= n; i ++ ) if(nxt[i] != i) {
        int now = i ;
        vector<int> vc ;
        int s = 0 ; bool fl = 1 ;
        {
            vc = {i} ; now = nxt[i] ;
            if(vc.size()) {
                if(now - vc.back() > 1) fl &= !(nxt[now - 1] == nxt[now] && max(i , pre[now - 1]) < vc.back()) , s += nxt[now - 1] == nxt[now] ;
                if(now - vc.back() > 2) fl &= nxt[now - 2] != nxt[now] ;
            }
            if(!fl) continue ;
            if(!vc.size()) {   
            }else {
                if(vc.back() == now - 1 ) ans += (s == 1) * (nxt[now] - now) ;
                else {
                    ans += ( s == 1 ) * (nxt[now] - nxt[now - 1]) ;
                    s -= nxt[now - 1] == nxt[now] ;
                    if(!s && max( i , pre[now - 1] ) == vc.back() ) ans += (nxt[now - 1] - (now - vc.back() > 2 ? nxt[now - 2] : now) ) ;
                    s += nxt[now - 1] == nxt[now] ;
                }
            }
        }
        if(fl) {
            now = nxt[i] ;
            s = nxt[i] - i > 1 ? nxt[nxt[i] - 1] == nxt[nxt[i]] : 0 ;
            if(s) {
                int k = jp[now] ? jp[now] : n + 1;
                int td = gg[now] ? gg[now] : n + 1 ;
                ans += zz[now][s] - zz[min(td , k)][s] ;
            }else {
                int k = jp[now] ? jp[now] : n + 1 ;
                int td = gg[now] ? gg[now] : n + 1 ;
                if(k >= td) ans += zz[now][s] - zz[td][s] ;
                else {
                    // cout << now << ' ' << k << '\n' ;
                    ans += zz[now][s] - zz[k][s] ;
                    s ++ ;
                    now = k ;
                    k = jp[nxt[now]] ? jp[nxt[now]] : 0 ;
                    ans += zz[now][s] - zz[min(td , k)][s] ;
                }
            }
            // while(ok[now]) {
            //     s += nxt[now] - now > 1 ? nxt[nxt[now] - 1] == nxt[nxt[now]] : 0 ;
            //     if(s > 1) break ;
            //     ans += zz[now][s] ;
            //     now = nxt[now] ;
            // }
        }
    } 
    
    cout << ans << '\n' ;
}
signed main() {
    freopen("migrate.in","r",stdin) ;
    freopen("migrate.out","w",stdout) ;
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
    int c , t ;
    cin >> c >> t ;
    while(t --) solve() ;
    return 0 ;  
}