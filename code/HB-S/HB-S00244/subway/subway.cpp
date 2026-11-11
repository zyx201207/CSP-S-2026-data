#include <bits/stdc++.h>
#define lx long long

using namespace std;
const lx N = 505 , M = 5e5 + 5;
lx c , n , m , d , q , w[N] , dis[N] , a[N];
vector <pair <lx , lx> > e[M];
bool vis[N];
lx dijkstra (lx x , lx y) {
    memset (vis , 0 , sizeof (vis));
    memset (dis , 0x3f , sizeof (dis));
    priority_queue <pair <lx , lx> , vector <pair <lx , lx> > , greater <pair <lx , lx> > > q;
    dis[x] = w[x] + a[x];
    q.push (make_pair (w[x] + a[x] , x));
    while (!q.empty ()) {
        auto now = q.top ();
        q.pop ();
        lx d = now.first , u = now.second;
        if (vis[u]) continue;
        vis[u] = 1;
        for (lx i = 0 ; i < e[u].size () ; i ++) {
            lx v = e[u][i].second , w = e[u][i].first;
            if (dis[v] > dis[u] + w && v != u) {
                dis[v] = dis[u] + w;
                if (v != y && !vis[v] && v <= n) dis[v] += e[v][0].first;
                q.push (make_pair (dis[v] , v));
            }
        }
    }
    if (dis[y] == 0x3f3f3f3f) return 0;
    return dis[y] + w[y];
}
int main () {
    freopen ("subway.in" , "r" , stdin);
    freopen ("subway.out" , "w" , stdout);
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    cin >> c >> n >> m >> d >> q;
    for (lx i = 1 ; i <= m ; i ++) cin >> w[i];
    for (lx i = 1 , k ; i <= n ; i ++) {
        cin >> k;
        for (lx j = 1 , u , w ; j <= k ; j ++) {
            cin >> u >> w;
            e[i].push_back ({w , u});
            if (i == u) a[i] = w;
        }
    }
    for (lx i = 1 ; i <= q ; i ++) {
        lx x , y;
        cin >> x >> y;
        cout << dijkstra (x , y) << endl;
    }
    return 0;
}
