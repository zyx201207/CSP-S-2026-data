#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 5;
int N, M;
int a[MAXN], lst[MAXN], nxt[MAXN], num[MAXN], st[MAXN], ed[MAXN];
bool vis[MAXN];
// int ans[MAXN];
set<pair<int, int>> stt;
void slove(){
    bool flg = 1;
    cin >> N >> M;
    for( int i = 1; i <= N; i ++ ){
        cin >> a[i];
        if( a[i] < a[i - 1] ) flg = 0;
        lst[i] = num[a[i]];
        if( num[a[i]] == 0 ) st[a[i]] = i;
        num[a[i]] = i;
    }
    for( int i = 1; i <= M; i ++ ) num[i] = 0;
    for( int i = N; i >= 1; i -- ){
        nxt[i] = num[a[i]];
        if( num[a[i]] == 0 ) ed[a[i]] = i;
        num[a[i]] = i;
    }

    if( flg ){
        for( int i = 1; i <= M; i ++ ){
            cout << ed[i] << " ";
            // if( st[i] == 0 ) cout << 0 << " ";
            // else{
            //     // int now = ed[i] - st[i] + 1;

            //     // if( st[i] > M ) cout << N - st[i] + 1 << " ";
            //     // else cout << N - i + 1 << " ";
            // }
        }
        return;
    }
    if( N <= 500 ){
        for( int i = 1; i <= M; i ++ ){//哪个位置
            int ans = 0;
            for( int l = i; l <= N; l ++ ){//取哪些排
                for( int j = i; j <= N; j ++ ){//模拟取
                    // cerr << i << " " << j << " " << lst[a[j]] << "\n";
                    if( lst[a[j]] != 0 ){
                        for( int k = lst[a[j]]; k <= j; k ++ ){//收牌
                            vis[k] = 1;
                        }
                    }
                }
                for( int k = st[i]; k; k = nxt[k] ){
                    if( !vis[k] ) ans ++;
                    // cerr << k << " ";
                    // vis[k] = 0;
                }
                for( int k = 1; k <= N; k ++ ) vis[k] = 0;
            }
            cout << ans << " ";
        }
    }
    // for( knt i = 1; i <= M; i ++ ){
    //     ans[i] += ed[i] - st[i] + 1;
    //     for( int j = st[i]; j < ed[i]; j = nxt[j] ){
    //         for( int k = j; k <= nxt[j]; k ++ ){
    //             if( k >= a[k] ) ans[a[k]] -= max( 0ll, nxt[k] - k + 1 );
    //         }
    //     }
    // }
    // for( int i = 1; i <= M; i ++ ){
    //     cout << ans[i] << " ";
    // }
    return;
}

signed main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );
    freopen( "card.in", "r", stdin );
    freopen( "card.out", "w", stdout );
    int T = 1;
    // cin >> T;
    while( T -- )
        slove();
    return 0;
}