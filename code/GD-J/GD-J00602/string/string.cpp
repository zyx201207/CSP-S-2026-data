#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5;
int N, sum, cnt1, cnt2, ans;
struct node{
    int a;
    char c;
}a[MAXN];
void slove(){
    cin >> N;
    for( int i = 1; i <= N; i ++ ){
        cin >> a[i].a >> a[i].c;
        sum += a[i].a;
    }
    for( int i = 1, j = N; i <= j && i <= N; i ++ ){
        cnt1 += a[i].a;
        int lst = a[i].a;
        // cerr << "1 " << j << " " << a[j].a << "\n";
        // cerr << i << " " << j << " " << cnt1 << " " << cnt2 << " " << a[j].a << "\n";
        if( cnt2 > cnt1 ){
            if( a[i].c != a[j].c ) ans += a[i].a;
            a[j].a -= a[i].a;
            // cerr << "2 " << j << " " << a[j].a << "\n";
            continue;
        }
        while( i <= j && j >= 1 && cnt2 <= cnt1 ){
            cnt2 += a[j].a;
            // cerr << "3 " << j << " " << a[j].a << "\n";
            // cerr << j << " * " << a[j].a << " " << cnt1 << " " << cnt2 << "\n";
            if( cnt2 <= cnt1 ){
                // cerr << "5 " << j << " " << a[j].a << "\n";
                if( a[i].c != a[j].c ) ans += a[j].a;
                lst -= a[j].a;
                j --;
            } else{
                //  cerr << "6 " << j << " " << a[j].a << " " << lst << "\n";
                if( a[i].c != a[j].c ) ans += lst;
                cnt2 -= ( a[j].a - lst );
                a[j].a -= lst;
                // cerr << lst << "\n";
                break;
            }
        }
        // cerr << "4 " << j << " " << a[j].a << "\n";
        // cerr << i << "|" << j << " " << cnt1 << " " << cnt2 << " " << a[j].a << "\n";
    }
    cout << ans;
    return;
}

signed main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );
    freopen( "string.in", "r", stdin );
    freopen( "string.out", "w", stdout );
    int T = 1;
    // cin >> T;
    while( T -- )
        slove();
    return 0;
}
// cnt1 += a[i].a;
// while( j >= 1 && j >= i && cnt2 <= cnt1 ){
//     cnt2 += a[j].a;
//     if( a[i].c != a[j].c ){
//         if( cnt2 <= cnt1 ){
//             a[i].a -= a[j].a;
//             ans += a[i].a - a[j].a;
//         }
//     }
//     j --;
// }
// cerr << i << " " << j << "\n";
// if( a[i].c != a[j].c && cnt1 <= cnt2 ){
//     ans += a[i].a;
//     cnt1 += a[i].a;
//     i ++;
//     continue;
// }
// while( j >= 1 && j >= i && cnt2 + a[j].a <= cnt1 ){
//     cerr << i << " " << j << " " << cnt1 << " " << cnt2 << "\n";
//     if( a[i].c != a[j].c ) ans += a[j].a, cnt2 += a[j].a;
//     a[i].a -= a[j].a;
//     j --;
//     cerr << ans << "\n";
// }
// cerr << i << " " << j << " " << cnt1 << " " << cnt2 << "\n";
// if( a[i].c != a[j].c ){
//     if( cnt1 <= cnt2 ) ans += a[i].a;
//     else ans += a[j].a;
// }