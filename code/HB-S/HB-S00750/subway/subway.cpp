#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, w;
    bool operator<(Edge rhs) {
        return w < rhs.w;
    }
};
vector<Edge> e[505]; // [u].v/w
int a[505];   // tiekou dao chezhan
int de[505] = {0x7FFF0000}; // zheduima
    int c, n, m, d, q;  //c:x n:bianshu m:dianshu d:x q:xunwencishu

void dijkstra(int u, int fa) {
    for (auto edge: e[u]) {
            //if (edge.v == fa) continue;
        de[edge.v] = min(de[u] + edge.w, de[edge.v]);
        //cout << "dijk: " << u << ' ' << edge.v << ' ' << edge.w << ' ' << endl;
        ///cout << ":" << de[edge.v] << ' ' << de[u] << ' ' << edge.w << endl;
        //    for (int j = 1; j <= m; j++) {
        //        cout << de[j] << ' ';
        //    }
        //cout << endl;
        dijkstra(edge.v, u);

    }
}

void solve(int start, int end){
    dijkstra(start, 0);
    cout << de[end] << endl;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int k;  // changdu
        cin >> k;
            int last_v, lastw;
            cin >> last_v >> lastw;
        for (int j=1; j < k ; j++) {

            int v, w;
            cin >> v >> w;
            e[last_v].push_back({v, w});
            //e[v].push_back({last_v, w});
            //cout << ";;" << v << ' ' << last_v ;
            last_v = v;
        }
    }
    //cout << "input:";
    //for (int u = 0; u < m; u++) {
    //    for (auto edge: e[u]) {
    ///        cout << u << "/" << edge.v << "/" << edge.w << ' ';
    //    }
    //    cout << endl;
    //}
    cout << endl;
    for (int i = 0; i < q; i++) {
        for (int i = 0 ;i < m; i++) {
            de[i] = 0x7FFF0000;
        }

        int start, end;
        cin >> start >> end;
        de[start] = 0;
        solve(start, end);
    }
    return 0;
}





































































































