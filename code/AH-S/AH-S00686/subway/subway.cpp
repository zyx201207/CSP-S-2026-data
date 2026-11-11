#include <bits/stdc++.h>
using namespace std;

const int Node = 1e6 + 10, Edge = 2e5 + 10, M = 5e5 + 5,
    N = 505, Q = 1e5 + 5;

using ull = unsigned long long;
using ll = long long;
// using ull = __int128;
// struct graph{
//     int head[N], next[Edge], to[Node], w[Node], cnt;
//     graph(){
//         cnt = 0;
//         memset(head, -1, sizeof head);
//         memset(next, -1, sizeof next);
//     }

//     void add_edge1(int u, int v, int we){
//         cnt++;
//         next[cnt] = head[u];
//         head[u] = cnt;
//         to[cnt] = v;
//         w[cnt] = we;
//     }

//     void add_edge(int u, int v, int we){
//         add_edge1(u, v, we);
//         add_edge1(v, u, we);
//     }
// } G;

ull G[N][N];

int c, n, m, d, q;
int w[M];
vector<pair<int, int>> lines[M];
pair<int, int> rides[Q];

void input(){
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int a, t;
            cin >> a >> t;
            lines[a].push_back(make_pair(i, t));
        }
    }
}

void make_graph(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)//(int)(1e9 + 5);
            G[i][j] = (i==j) ? 0 : ((ULLONG_MAX>>1)-5);
    for (int i = 1; i <= m; i++){
        int l = lines[i].size();
        for (int a = 0; a < l - 1; a++){
            int u = lines[i][a].first;
            for (int b = a + 1; b < l; b++){
                int v = lines[i][b].first;
                int w = lines[i][a].second + lines[i][b].second;
                G[u][v] = min(G[u][v], (ull)w);
                G[v][u] = min(G[v][u], (ull)w);
            }
        }
    }
}

void Floyd(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}


int main(){
    // ull x = ULLONG_MAX;
    // cout << x;
    // cout << ULLONG_MAX;
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    input();
    make_graph();
    Floyd();
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         cout << G[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        ull ans = ULLONG_MAX;
        for (pair<int, int> p1: lines[x])
            for (pair<int, int> p2: lines[y]){
                ans = min(ans, (ull)p1.second + p2.second + G[p1.first][p2.first]);
        }
        ans += w[x] + w[y];
        cout << ans << '\n';
    }
    return 0;
}