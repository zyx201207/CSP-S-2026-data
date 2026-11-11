#include<bits/stdc++.h>
using namespace std; 
const int N = 1e6 + 10 ;
int n , k , m ;
vector<int> g[N] ;
int d[N] , ans[N] , mx[N] ;
void dfs(int u , int f = 0) {
    mx[u] = 0 ; 
    for(int v : g[u] ) if(v != f) dfs(v ,u ), mx[u] = max(mx[u] , mx[v] + 1 ) ; 
    d[u] = mx[u] >= m ;
}
int pre[N] , suf[N] , mm[N] ;
void dfs3(int u , int f = 0 ) {
    for(int v : g[u] ) if(v != f) dfs3(v , u) , d[u] += d[v] ;
}
map<pair<int , int> , int> zp ;
void dfs2(int u , int s = 0 , int di = - n , int f = 0) {
    int all = 0 ;
    for(int i = 0 ; i < g[u].size() ; i ++ ) {
        pre[i] = -1 ;
        if(g[u][i] != f) { pre[i] = mx[g[u][i]]; all += d[g[u][i]] ;}
        if(i) pre[i] = max(pre[i] , pre[i - 1] ) ;
    }
    for(int i = (int)g[u].size() - 1 ; ~i; i -- ) {
        suf[i] = -1 ;
        if(g[u][i] != f)suf[i] = mx[g[u][i]] ; 
        if(i + 1 < g[u].size() ) suf[i] = max(suf[i] , suf[i + 1] ) ;
    }
    int c = -1; 
    for(int v : g[u]) {
        ++ c ; if(v == f) continue ;
        int T = 0 ;
        if(c) T = max(T , pre[c - 1] + 1) ;
        if(c + 1 < g[u].size()) T = max(T , suf[c + 1] + 1) ;
        mm[v] = T ;
    }
    for(int v : g[u] ) if(v != f) {
        int r = d[u] - d[v] + s - (mx[u] >= m) + (max(di , mm[v]) >= m) ;
        zp[{u , v}] = max( 1 , r) ;
        dfs2(v , s + (max(di , mm[v]) >= m) + all - d[v] , max(di, mm[v]) + 1 , u) ; 
    }
    ans[u] = d[u] + s - (mx[u] >= m) + (max(mx[u] , di) >= m) ;
    if(f) zp[{u , f}] = max(1 , d[u]) ;
}
bool fl ; 
int mnc , Mn[N] ;
void dfs5(int u ,int f = 0) {
    mx[u] = 0 ;
    for(int v : g[u] ) if(v != f) dfs5(v , u) , mx[u] = max(mx[u] , mx[v] + 1);
    for(int i = 0 ; i < g[u].size() ; i ++ ) {
        if(g[u][i] != f) { pre[i] = mx[g[u][i]]; }
        else pre[i] = -1 ;
        if(i) pre[i] = max(pre[i] , pre[i - 1] ) ;
    } // cout << u << ' ' << mx[u] << '\n' ;
    for(int i = (int)g[u].size() - 1 ; ~i; i -- ) {
        if(g[u][i] != f)suf[i] = mx[g[u][i]] ; 
        else suf[i] = -1 ;
        if(i + 1 < g[u].size() ) suf[i] = max(suf[i] , suf[i + 1] ) ;
    } int c = -1; 
    for(int v : g[u] ) {
        ++ c ; if(v == f) continue ;
        Mn[v] = 0 ;
        if(c) Mn[v] = max(Mn[v] , pre[c - 1] + 1) ;
        if(c + 1 < g[u].size()) Mn[v] = max(Mn[v] , suf[c + 1] + 1 ) ;
        // cout << "^" << v << ' ' << Mn[v] << ' ' << '\n';
    } 
}
void dfs4(int u , int f , int d = 0 , int S = n) {
    if(Mn[u] + d <= m) {}
    else S = min(S , m - Mn[u] + d) ;
    // cout << u << " " << Mn[u] << ' ' << S << '\n' ;
    if(d >= S) return ;
    mnc = min(mnc , zp[{u , f}]) ;
    for(int v : g[u] ) if(v != f) dfs4(v , u , d + 1 , S) ;
}
bool chk(int x) {
    zp.clear() ;
    m = x ; dfs(1) ; dfs3(1) ; dfs2(1) ; 
    fl = 0 ;
    for(int i = 1 ; i <= n ; i ++ ) fl |= ans[i] <= k ;
    for(int i = 1 ; i <= n ; i ++ ) {
        dfs5(i , 0) ;
        for(int v :g[i] ) {
            mnc = 1e9 ;
            dfs4(v ,i ) ;
            // cout << i << ' ' << v << ' ' << m << ' ' << mnc << ' ' << zp[{i , v}] << '\n' ;
            fl |= mnc + zp[{i , v}] <= k ;
        }
    }
    return fl ;
}
void solve() {
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; i ++ ) g[i].clear() ;
    for(int i = 1; i < n ; i ++ ) {
        int x, y ; cin >> x >> y ;
        g[x].push_back(y) ; g[y].push_back(x) ;
    }
    int l = 0 , r = n , ans = n ;
    chk(1) ;
    while(l <= r) {
        int mi = l + r >> 1 ;
        if(chk(mi)) ans = mi , r = mi - 1 ;
        else l = mi + 1; 
    }  cout << ans << '\n' ;
}
int main() {
    freopen("hub.in","r",stdin) ;
    freopen("hub.out","w",stdout) ;
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
    int c , t ;
    cin >> c >> t ;
    while (t -- ) solve() ;
    return 0 ;
}