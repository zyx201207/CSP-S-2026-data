#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int , ll > pt;
typedef pair < ll , int > pr;
const int N = 8e5 + 5 , M = 5005;
int c , m , n , dt , q;
bool book[N];
ll w[N] , f[M][M] , d[N];
vector < pt > e[N];

inline ll dijk (int st , int ed) {
    for (int i = 0; i <= n; i ++)
        d[i] = 0x3f3f3f3f3f3f3f3f , book[i] = 0;
    priority_queue < pr , vector < pr > , greater < pr > > q;
    d[st] = 0;
    q.push({d[st] , st});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (book[u])
            continue;
        book[u] = 1;
        for (pt i : e[u]) {
            int v = i.first;
            ll w = i.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.push({d[v] , v});
            }
        }
    }
    return d[ed];
}

int main () {
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> c >> m >> n >> dt >> q;
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    if (q <= 2000) {
        for (int i = 1; i <= m; i ++) {
            int k , u = ++ n;
            cin >> k;
            for (int j = 1; j <= k; j ++) {
                int v;
                ll w;
                cin >> v >> w;
                e[u].push_back({v , w});
                e[v].push_back({u , w});
            }
        }
        while (q --) {
            int u , v;
            cin >> u >> v;
            cout << w[u] + w[v] + dijk(u , v) << "\n";
        }
    }
    else {
        for (int i = 0; i <= 5000; i ++)
            for (int j = 0; j <= 5000; j ++)
                f[i][j] = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= m; i ++) {
            int k , u = ++ n;
            cin >> k;
            for (int j = 1; j <= k; j ++) {
                int v;
                ll w;
                cin >> v >> w;
                f[u][v] = min(f[u][v] , w);
                f[v][u] = min(f[v][u] , w);
            }
        }
        for (int k = 1; k <= n; k ++)
            for (int i = 1; i <= n; i ++)
                for (int j = 1; j <= n; j ++)
                    f[i][j] = min(f[i][j] , f[i][k] + f[k][j]);
        while (q --) {
            int u , v;
            cin >> u >> v;
            cout << w[u] + w[v] + f[u][v] << "\n";
        }
    }
    return 0;
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
* 
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

 * */
