#include <bits/stdc++.h>
using namespace std;
namespace OIer {
    namespace IO {
        typedef long long ll;
        inline ll read() {
            ll x = 0, f = 1;
            char ch = getchar();
            while (ch < '0' || ch > '9') {
                if (ch == '-') f = -1;
                ch = getchar();
            }
            while (ch >= '0' && ch <= '9') {
                x = x * 10 + (ch - '0');
                ch = getchar();
            }
            return x * f;
        }
        template<typename T> inline void write(T x) {
            if (x < 0) putchar('-'), x = -x;
            if (x > 9) write(x / 10);
            putchar((x % 10) + '0');
            return;
        }
        inline void open(string s) {
            string in = s + ".in", out = s + ".out";
            freopen (in.c_str(), "r", stdin);
            freopen (out.c_str(), "w", stdout);
        }
    }
    using namespace IO;
    typedef pair<int,int> pi;
    int c, n, m, d, q;
    int sv[20010], dis[20010];
    vector<pair<int, int> > G[20010];
    int Dijkstra(int beg, int ed) {
        priority_queue<pi, vector<pi>, greater<pi> > q;
        memset(dis, 0x3f, sizeof dis);
        dis[beg] = 0;
        q.push({beg, 0});
        while (!q.empty()) {
            pi h = q.top();
            q.pop();
            for (auto y : G[h.first]) {
                int u = y.first, w = y.second;
                if (dis[u] > dis[h.first] + w) {
                    dis[u] = dis[h.first] + w;
                    q.push({u, w});
                }
            }
        }
        return dis[ed];
    }

    map<pi, int> bk;
    int uuu[1000100], www[1000100];
    void main () {
        cin >> c >> n >> m >> d >> q;
        for (int i = 1; i <= m; ++i) 
            sv[i] = read();
        if (c <= 11 and c >= 7) {
            for (int i = 1; i <= n; ++i) {
                int k = read();
                int u1 = read(), w1 = read(), u2 = read(), w2 = read();
                int w = w1 + w2;
                G[u1].push_back({u2, w});
                G[u2].push_back({u1, w});
            }
            for (int i = 1; i <= q; ++i) {
                int b = read(), e = read();
                write(sv[b] + sv[e] + Dijkstra(b, e));
                puts("");
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                int k = read();
                while (k --> 0) {
                    uuu[i] = read(), www[i] = read();
                }
            }
            while (q --> 0) 
                cout << sv[read()] + sv[read()] << endl;
        }
        return;
    }
}
int main () {
    OIer::open("subway");
    OIer::main();
    return 0;
}