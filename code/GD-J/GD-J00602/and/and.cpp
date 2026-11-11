#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5;
int N, M, now[34];
int tot[34];
vector<pair<int, int>> tt[34];
struct node{
    int a, b[34];
}a[MAXN];

bool cmp( pair<int, int> aa, pair<int, int> bb ){
    if( aa.first == -1 ) return false;
    if( bb.first == -1 ) return true;
    return a[aa.first].a > a[bb.first].a;
}

bool ccmp( pair<int, int> a, pair<int, int> b ){
    return a.second > b.second;
}
bool vis[MAXN];
void slove(){
    cin >> N >> M;
    for( int i = 1; i <= N; i ++ ){
        cin >> a[i].a;
        int cnt = 0;
        for( int j = 0; j <= 31; j ++ ){
            a[i].b[j] = ( ( a[i].a >> j ) & 1 );
            tot[j] += a[i].b[j];
            // cerr << j << " " << a[i].b[j] << "\n";
            // cnt += a[i].b[j];
            if( a[i].b[j] == 1 ) tt[j].push_back({ i, cnt });
        }
        // for( int j = 0; j <= 31; j ++ ){
        // }
    }

    for( int i = 31; i >= 0; i -- ){
        if( tot[i] >= M ){
            if( (long long)tt[i].size() < M ) continue;
            sort( tt[i].begin(), tt[i].end(), cmp );
            int ans = a[tt[i][0].first].a;
            // sort( tt[i].begin(), tt[i].end(), ccmp );
            for( int j = 1; j < M; j ++ ){
                ans &= a[tt[i][j].first].a;
            }
            cout << ans;
            return;
        }
    }
    cout << 0;
    // sort( a + 1, a + N + 1, cmp );
    
    return;
}

signed main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );
    freopen( "and.in", "r", stdin );
    freopen( "and.out", "w", stdout );
    int T = 1;
    // cin >> T;
    while( T -- )
        slove();
    return 0;
}
// for( int i = 0; i <= 31; i ++ ){
//     sort( tot[i].begin(), tot[i].end(), ccmp );
//     for( auto x : tot[i] ) cerr << i << " " << x.first << " ";
//     cerr << endl; 
// }

// int ccnt = 0;
// for( int i = 0; i <= 31; i ++ ){
//     if( now[i] == 0 ){
//         if( tot[i].empty() ) continue;
//         ccnt ++;
//         cerr << tot[i][0].first << " ";
//         for( int j = 0; j <= 31; j ++ ){
//             now[j] &= a[tot[i][0].first].b[j];
//             cerr << " " << a[tot[i][0].first].b[j];
//         }
//         cerr <<"\n";
//         if( ccnt >= M ) break;
//         // vis[tot[i][0].first] = 1;
//     }
// }