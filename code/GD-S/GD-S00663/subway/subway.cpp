#include<bits/stdc++.h>
#define int long long// 17:18 exp: 100pts!!!
using namespace std;
const int MAXN = 5e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, D, Q;// 线路数 地铁站数 每个地铁站最多被多少条线路经过
int w[MAXN];
// vector<pair<int, int>> vc[MAXN];//vc[i]表示第 i 条线路经过哪些地铁站 -> 第 i 个点连出了哪些边
vector<pair<int, int>> vcc[MAXN];//vcc[i]表示第 i 个地铁站有哪些出边 -> 有哪些边用了第 i 个站台的名义
struct star{
    int nxt, to, w;
}edge[MAXN << 1];
int head[MAXN], cnt;
void add( int u, int v, int w ){
    // cerr << u << " " << v << " " << w << "\n";
    edge[++ cnt] = { head[u], v, w };
    head[u] = cnt;
}

struct node{
    int id, x;
    bool operator < ( const node & nd ) const {
        return x > nd.x;
    }
};
priority_queue<node> pq;
int dis[MAXN];
bool vis[MAXN];
void dij( int st, int www ){
    for( int i = 1; i <= N; i ++ )
        dis[i] = inf, vis[i] = 0;
    dis[st] = www;
    pq.push({ st, w[st] });
    while( !pq.empty() ){
        int u = pq.top().id;
        pq.pop();
        if( vis[u] ) continue;
        vis[u] = true;
        for( int i = head[u]; i; i = edge[i].nxt ){
            int v = edge[i].to;
            if( dis[v] > dis[u] + edge[i].w ){
                dis[v] = dis[u] + edge[i].w;
                pq.push({ v, dis[v] });
            }
        }
    }
}

void slove(){
    cin >> N >> M >> D >> Q;
    for( int i = 1; i <= M; i ++ ){
        cin >> w[i];
    }
    for( int i = 1; i <= N; i ++ ){
        int k;
        cin >> k;
        for( int j = 1; j <= k; j ++ ){
            int a, b;
            cin >> a >> b;
            // vc[i].push_back({ a, b });
            vcc[a].push_back({ i, b });
            // cerr << a << " " << vcc[a].size() << "\n";
        }
        // for( int j = 0; j < k; j ++ ){
        //     for( int l = j + 1; l < k; l ++ ){
        //         add( vc[j].first, vc[l].first, vc[j].second + vc[l].second );
        //     }
        // }
    }
    // cerr << "\n-----------------------\n";
    for( int i = 1; i < M; i ++ ){
        for( int j = 0; j < vcc[i].size(); j ++ ){
            for( int k = j + 1; k < vcc[i].size(); k ++ ){
                add( vcc[i][j].first, vcc[i][k].first, vcc[i][j].second + vcc[i][k].second );
                add( vcc[i][k].first, vcc[i][j].first, vcc[i][k].second + vcc[i][j].second );
            }
        }
    }
    // cerr << "\n-----------------------\n";
    while( Q -- ){
        int x, y, ans = inf;
        cin >> x >> y;
        // cerr << x << " " << vcc[x].size() << "\n";
        for( int i = 0; i < vcc[x].size(); i ++ ){
            // cerr << vcc[x][i].first << "\n";
            dij( vcc[x][i].first, vcc[x][i].second + w[x] );
            for( int j = 0; j < vcc[y].size(); j ++ ){
                ans = min( ans, dis[vcc[y][j].first] + vcc[y][j].second + w[y] );
            }
        }
        cout << ans << "\n";
    }
    return;
}

signed main(){
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );
    freopen( "subway.in", "r", stdin );
    freopen( "subway.out", "w", stdout );
    int C = 1, T = 1;
    cin >> C;
    // cin >> T;
    while( T -- )
        slove();
    return 0;
}