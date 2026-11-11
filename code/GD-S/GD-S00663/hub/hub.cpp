#include<bits/stdc++.h>
#define int long long// 17:05 exp: 15 pts.（但是为什么 k <= 2 的那几个点会 re 我没明白
using namespace std;
const int MAXN = 5e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, K;
struct star{
    int nxt, to;
}edge[MAXN << 1];
int head[MAXN], cnt;
void add( int u, int v ){
    // cout << u << " " << v << "\n";
    edge[++ cnt] = { head[u], v };
    head[u] = cnt;
}

int f[MAXN][32], dep[MAXN];
void dfs( int u, int fa ){
    // cerr << u << " " << fa << "\n";
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for( int i = 1; i <= 30; i ++ ){
        f[u][i] = f[f[u][i - 1]][i - 1];
        // cout << u << " " << i << " " << f[u][i] << " " <<f[u][i - 1] << "\n";
    }
    for( int i = head[u]; i; i = edge[i].nxt ){
        int v = edge[i].to;
        if( v == fa ) continue;
        dfs( v, u );
    }
}

int lca( int x, int y ){
    // cout << x << " " << y << "\n";
    if( dep[x] < dep[y] ) swap( x, y );
    for( int i = 30; i >= 0; i -- ){
        if( dep[f[x][i]] >= dep[y] ) x = f[x][i];
    }
    // cout << x << " " << y << "\n";
    if( x == y ) return x;
    for( int i = 30; i >= 0; i -- ){
        if( f[x][i] != f[y][i] ) x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}

int res = inf;
bool vis[MAXN];
int faa[MAXN];
int find( int x ){
    if( faa[x] == x ) return x;
    return faa[x] = find( faa[x] );
}

void join( int x, int y ){
    int fx = find( x ), fy = find( y );
    if( fx != fy ){
        faa[fy] = fx;
    }
}
set<int> st;
vector<int> vc;
void ddfs( int depp, int lst ){
    // cerr << dep << " " << lst << "\n";
    if( depp > N ){
        if( lst != 0 ) return;
        for( int i = 1; i <= N; i ++ ) faa[i] = i;
        // cerr << "1\n";
        // for( int x : vc ) cerr << x << " ";
        // cerr << "\n";
        // cerr <<"\n===================\n";
        for( int i = 1; i <= N; i ++ ){
            // cerr << "\n";
            // cerr << "\n-----------------\n";
            if( vis[i] == 0 ) continue;
            for( int j = head[i]; j; j = edge[j].nxt ){
                int v = edge[j].to;
                // cerr << i << "*" << v << "\n"
                if( vis[v] ) join( i, v );
            }
        }
        // cerr <<"\n===================\n";
        // for( int i = 1; i <= N; i ++ ){
        //     if( vis[i] ){
        //         for( int j = head[i]; j; j = edge[j].nxt ){
        //             int v = edge[j].to;
        //             if( vis[v] ){ cerr << i << " " << v << "\n", join( i, v );}
        //         }
        //     }
        // }
        st.clear();
        for( int i = 1; i <= N; i ++ ){
            if( vis[i] ) st.insert( find( i ) );
        }
        // for( int x : st ) cerr << x << " ";
        // cerr << "\n";
        if( st.size() >= 3 ) return;
        int ans = 0;
        // cerr << "2\n";
        // for( int x : vc ) cerr << x << " ";
        // cerr << "\n";
        for( int i = 1; i <= N; i ++ ){
            if( vis[i] ) continue;
            int now = inf;
            for( int x : vc ){
                int k = lca( x, i );
                now = min( now, dep[i] + dep[x] - 2 * dep[k] );
                // cerr << i << " " << x << " " << lca( x, i ) << "\n";
            }
            ans = max( now, ans );
        }
        // if( ans == 1 ){
        //     for( int x : vc ) cerr << x << " ";
        // }
        // cerr <<"\n===================\n";
        res = min( res, ans );
        return;
    }
    ddfs( depp + 1, lst );
    if( lst >= 1 ){
        vis[depp] = 1;
        vc.push_back( depp );
        ddfs( depp + 1, lst - 1 );
        vc.pop_back();
        vis[depp] = 0;
    }
}

void slove(){
    cin >> N >> K;
    for( int i = 1; i < N; i ++ ){
        int u, v;
        cin >> u >> v;
        add( u, v ), add( v, u );
    }
    // for( int i = 1; i <= N; i ++ ){
    //     for( int j = head[i]; j; j = edge[j].nxt ){
    //         cout << i << " " << edge[j].to << "\n";
    //     }
    // }
    dfs( 1, 0 );
    ddfs( 1, K );
    cout << res << "\n";
    for( int i = 1; i <= N; i ++ ){
        head[i] = dep[i] = 0;
        vis[i] = 0;
        for( int j = 0; j <= 31; j ++ ) f[i][j] = 0;
    }
    cnt = 0, res = inf;
    return;
}

signed main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );
    freopen( "hub.in", "r", stdin );
    freopen( "hub.out", "w", stdout );
    int C, T = 1;
    cin >> C;
    cin >> T;
    while( T -- )
        slove();
    return 0;
}