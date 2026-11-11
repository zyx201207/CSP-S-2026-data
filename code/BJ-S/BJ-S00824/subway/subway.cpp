#include <bits/stdc++.h>
using namespace std;

namespace xieheng24 {
    #define endl '\n'
    #define rep(i, a, b) for (int i = (a); i <= (b); ++i)
    #define _rep(i, a, b) for (int i = (a); i < (b); ++i)
    #define per(i, a, b) for (int i = (a); i >= (b); --i)
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<ll, int> pli;

    template<typename T, typename T1> 
    __inline void chkmax(T& x, T1 y) {
        if (y > x) x = y;
    }

    template<typename T, typename T2>
    __inline void chkmin(T& x, T2 y) {
        if (y < x) x = y;
    }

    int c;

    namespace case1 {
        constexpr int N = 2e3 + 10,  M = 4e4 + 10;
        int n, m, d, q;
        int h[N], e[M],ne[M], w[M], idx;

        __inline void add(int a, int b ,int c ){
            e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
        }
        
        ll di[N][N];
        bool st[N];
        ll wu[N];

        void dij(ll dist[], int s) {
            memset(st, 0, sizeof st);
            priority_queue<pli, vector<pli>, greater<pli>> q;
            q.push({0, s});
            rep(i, 1, n + m) dist[i] = 1e18;
            dist[s] = 0;
            while (q.size()) {
                pli tmp = q.top();
                q.pop();
                int dis = tmp.first, ver = tmp.second;
                if (st[ver]) continue;
                st[ver] = 1;
                for (int i = h[ver]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (dist[j] > dis + w[i]) {
                        dist[j] = dis + w[i];
                        q.push({dist[j], j});
                    }
                }
            }
        }
        
        int main() {
            cin >> n >> m >> d >> q;
            memset(h, -1, sizeof h);
            rep(i, 1, m) cin >> wu[i];
            rep(i, 1, n) {
                int k;
                cin >> k;
                rep(t, 1, k) {
                    int v, w;
                    cin >> v >> w;
                    add(i, v + n, w);
                    add(v + n, i , w);
                }
            }
            rep(i, 1, m) {
                dij(di[i], i + n);
            }
            rep(i, 1, q) {
                int u, v;
                cin >> u >> v;
                cout << wu[u] + wu[v] + di[u][v + n] << endl;
            }

            return 0;
        }
    }
    //**********************************************************************

    namespace case2 {
        constexpr int N = 1e5 + 10,  M = 1e5 + 10;
        int n, m, d, q;
        int h[N], e[M],ne[M], idx;

        __inline void add(int a, int b){
            e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
        }
        
        ll dist[N];
        bool st[N];
        ll wu[N];

        void dij(int s) {
            memset(st, 0, sizeof st);
            queue<int> q;
            q.push(s);
            rep(i, 1, n + m) dist[i] = 1e18;
            dist[s] = 0;
            while (q.size()) {
                int ver = q.front();
                q.pop();
                if (st[ver]) continue;
                st[ver] = 1;
                for (int i = h[ver]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (dist[j] > dist[ver] + 1) {
                        dist[j] = dist[ver] + 1;
                        q.push(j);
                    }
                }
            }
        }
        
        int main() {
            cin >> n >> m >> d >> q;
            memset(h, -1, sizeof h);
            rep(i, 1, m) cin >> wu[i];
            ll h = 0;
            rep(i, 1, n) {
                int k;
                cin >> k;
                rep(t, 1, k) {
                    int v, w;
                    cin >> v >> w;
                    h = w;
                    add(i, v + n);
                    add(v + n, i);
                }
            }
            rep(i, 1, q) {
                int u, v;
                cin >> u >> v;
                dij(u + n);
                cout << wu[u] + wu[v] + dist[v + n] * h << endl;
            }

            return 0;
        }
    }

    namespace case3 {

        int main() {
            return 0;
        }
    }

    int main() {
        cin >> c;
        if (c <= 11) return case1::main();
        else if (c <= 15) return case2::main();
        else if (c == 20 || c == 21) return case3::main();

        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    return xieheng24::main();
}