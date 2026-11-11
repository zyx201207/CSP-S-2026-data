#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#ifdef DEBUG
#define dbg(x) cout << "\033[33m" x << "\033[0m"
#else
#define dbg(x)
#endif



using ll = long long;
const ll INF = 1e18;
int c, n, m, d, q; // 测试编号，路线500，站台5e5，max度20，查询数1e5
struct Node {
    int v; ll t;
    friend auto &operator<<(ostream &out, Node nd) {
        return out << nd.v << ":" << nd.t;
    }
};
struct Upd {
    int v1, v2; ll t;
    friend bool operator>(Upd a, Upd b) {
        if(a.t != b.t) return a.t < b.t;
        if(a.v1 != b.v1) return a.v1 < b.v1;
        return a.v2 < b.v2;
    }
    friend bool operator<(Upd a, Upd b) {
        return b > a;
    }
    friend auto &operator<<(ostream &out, Upd upd) {
        return out << upd.v1 << " <-> " << upd.v2 << " t=" << upd.t;
    }
};
vector<Node> a[500005], g[600];
ll dist[600][600];
ll w[500005];



int main() {
    #ifndef DEBUG
        if(
            nullptr == freopen("subway.in" , "r", stdin ) ||
            nullptr == freopen("subway.out", "w", stdout)
        ) { return 1; }
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif



    cin >> c >> n >> m >> d >> q;
    for(int i=0; i<m; i++) {
        cin >> w[i];
    }
    for(int i=0; i<n; i++) {
        int len;
        cin >> len;
        for(int j=0; j<len; j++) {
            int id;
            ll time;
            cin >> id >> time;
            id--;
            a[id].push_back({i, time});
        }
    }
    // for(int i=0; i<m; i++) {
    //     dbg( << i+1 << " station:   ");
    //     for(const auto &nd: a[i]) {
    //         dbg( << "line " << nd.v+1 << " time " << nd.t << "    ");
    //     }
    //     dbg( << "\n");
    // }
    // dbg( << "\n");



    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for(int i=0; i<m; i++) {
        const int len = a[i].size();
        for(int j=0; j<len; j++) {
            for(int k=j+1; k<len; k++) {
                const auto &node1 = a[i][j], &node2 = a[i][k];
                const int v1 = node1.v, v2 = node2.v;
                const ll  t1 = node1.t, t2 = node2.t, t = t1+t2;
                if(t < dist[v1][v2]) {
                    dist[v2][v1] = dist[v1][v2] = t;
                }
            }
        }
    }
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         dbg( << dist[i][j] << " ");
    //     }
    //     dbg( << "\n");
    // }
    // dbg( << "\n");
    
    priority_queue<Upd> upds;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            const ll t = dist[i][j];
            if(t == INF) continue;
            g[i].push_back({j, t});
            g[j].push_back({i, t});
            upds.push({i, j, t});
            // upds.push({j, i, t});
            upds.push({i, j, t});
            // upds.push({j, i, t});
            // dbg( << "upd: " << i << " <-> " << j << " " << t << "\n");
            // auto upds2 = upds;
            // while(!upds2.empty()) {
            //     auto &upd = upds2.top(); upds2.pop();
            //     dbg( << upd << "\n");
            // }
        }
    }
    // dbg( << "\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    // for(int i=0; i<n; i++) {
    //     dbg( << "line " << i << ": ");
    //     for(const auto &nd: g[i]) {
    //         dbg( << nd << "   ");
    //     }
    //     dbg( << "\n");
    // }
    // dbg( << "\n");
    while(!upds.empty()) {
        // auto upds2 = upds;
        // while(!upds2.empty()) {
        //     auto &upd = upds2.top(); upds2.pop();
        //     dbg( << upd << "\n");
        // } dbg(<<"\n");
        const auto &ev = upds.top(); upds.pop();
        const int i = ev.v1, j= ev.v2;
        const ll t = ev.t;
        // if(t<0) return 1;
        // dbg( << "update:   " << i << " <-> " << j << " cost " << t << "   last " << dist[i][j] << "\n");
        if(t >= dist[i][j]) continue;
        dbg( << "update:   " << i << " <-> " << j << " cost " << t << "\n");
        dist[i][j] = dist[j][i] = t;
        for(const auto &nd: g[j]) {
            const int k = nd.v;
            const ll nt = t + dist[j][k];
            if(nt >= dist[i][k]) continue;
            upds.push({i, k, nt});
        }
        for(const auto &nd: g[i]) {
            const int k = nd.v;
            const ll nt = t + dist[i][k];
            if(nt >= dist[j][k]) continue;
            upds.push({j, k, nt});
        }
    }
    dbg( << "\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dbg( << dist[i][j] << " ");
        }
        dbg( << "\n");
    }
    dbg( << "\n");



    for(int i=0; i<q; i++) {
        int u1, u2;
        ll ans = INF;
        cin >> u1 >> u2;
        u1--; u2--;
        // dbg( << "query: " << u1 << " " << u2 << "\n");
        for(const auto &nd: a[u1]) {
            // dbg( << nd);
            const int v1 = nd.v;
            const ll  t1 = nd.t;
            for(const auto &nd: a[u2]) {
                const int v2 = nd.v;
                const ll  t2 = nd.t;
                const ll  t = t1 + t2 + dist[v1][v2];
                // dbg( << "   try:  " << v1 << ":" << t1 << "    " << v2 << ":" << t2 << "\n");
                if(t < ans) ans = t;
            }
        }
        // dbg( << "   ");
        cout << ans + w[u1] + w[u2] << "\n";
        // dbg( << "\n");
    }



    #ifndef DEBUG
        cout << flush;
        // fclose(stdin);
        // fclose(stdout);
    #endif
    return 0;
}