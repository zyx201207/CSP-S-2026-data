#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N];
int l[N];
int n , m;
int b[N];
int ans[N];

int main() {
    freopen( "card.in" , "r" , stdin );
    freopen( "card.out" , "w" , stdout );
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        memset( l , 0 , sizeof l );
        memset( b , 0 , sizeof b );
        int x = i - 1;
        for ( int j = i ; j <= n ; j ++ ) {
            if ( l[a[j]] == 0 || l[a[j]] > x ) {
                x ++;
                l[a[j]] = x;
                b[x] = a[j];
            }
            else if ( l[a[j]] <= x ){
                x = l[a[j]];
            }
            //cout << x << " ";
        }
        for ( int j = i ; j <= x ; j ++ ) {
            ans[b[j]] ++;
        }
        //cout << endl;
    }
    for ( int i = 1 ; i <= m ; i ++ ) {
        cout << ans[i] << " ";
    }
}
