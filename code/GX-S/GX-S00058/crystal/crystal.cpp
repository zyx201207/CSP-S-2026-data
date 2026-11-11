#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10 ;
ll val[maxn] , pre[maxn] , m ;
int n , r , ans ;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for ( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&val[i]);
    }
    sort ( val + 1 , val + n + 1 ) ;
    for ( int i = 1 ; i <= n ; i++ ){
        pre[i] = pre[i-1] + val[i] ;
    }
    for ( int i = 1 ; i <= n ; i++ ){
        r = max ( r , i - 1 ) ;
        while ( r < n && val[r+1] * ( r - i + 2 ) - ( pre[r+1] - pre[i-1] ) <= m ) r++;
        ans = max ( ans , r - i + 1 ) ;
    }
    printf("%d\n",ans);
    return 0 ;
}
