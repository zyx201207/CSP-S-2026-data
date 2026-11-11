#include <bits/stdc++.h>
using namespace std ;
long long a[510],g[510][510],v[510],n,m,d,q,ans,minn=2e9 ;
void b(int x,int y){
    if (x==y){
        minn=min(minn,ans) ;
        //cout << ":" << ans << endl ;
        return ;
    }
    v[x]=true ;
    for (long long i=1 ; i<=m ; i++){
        if (!v[i] && g[x][i]){
            //cout << x << "-" << i << " " ;
            v[i]=true ;
            ans+=g[x][i] ;
            ans+=g[x][x] ;
            b(i,y) ;
            //cout << x << "-" << i << " " ;
            ans-=g[x][i] ;
            ans-=g[x][x] ;
            v[i]=false ;
        }
    }
    return ;
}
int main () {
    freopen("subway.in" ,"r",stdin) ;
    freopen("subway.out","w",stdout) ;
    long long c ;
    cin >> c >> n >> m >> d >> q ;
    for (long long i=1 ; i<=m ; i++){
        cin >> a[i] ;
    }
    for (long long i=1 ; i<=n ; i++){
        long long k ;
        cin >> k ;
        for (long long j=1 ; j<=k ; j++){
            long long x,y ;
            cin >> x >> y ;
            g[i][x]=y ;
            g[x][i]=y ;
        }
    }
    for (long long i=1 ; i<=q ; i++){
        long long x,y ;
        cin >> x >> y ;
        ans=a[x]+a[y] ;
        minn=2e9 ;
        memset(v,0,sizeof(v)) ;
        b(x,y) ;
        cout << minn << endl ;
    }
    return 0 ;
}
