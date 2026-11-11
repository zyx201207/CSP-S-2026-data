#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define int long long
int w[500010];
vector<int> a[510], t[510];
struct Sta {
    int x, y;
};
vector<Sta> st[500010];
int g[510][510];
int dis[510][510];
struct Node {
    int x, w;
};
vector<Node> e[510];
bool operator <(Node x, Node y) {
    return x.w > y.w;
}
int c, n, m, d, q;
void dijkstra(int s, int dis[]) {
    for(int i = 1; i <= n; ++i)
        dis[i] = 1e15;
    priority_queue<Node> pq;
    dis[s] = 0;
    pq.push({s, 0});
    while(!pq.empty()) {
        Node t = pq.top();
        pq.pop();
        if(t.w != dis[t.x]) continue;
        for(Node i : e[t.x]) {
            if(dis[i.x] > dis[t.x] + i.w) {
                dis[i.x] = dis[t.x] + i.w;
                pq.push({i.x, dis[i.x]});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i)
        cin >> w[i];
    for(int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++j) {
            int ta, tt;
            cin >> ta >> tt;
            a[i].push_back(ta);
            t[i].push_back(tt);
            st[ta].push_back({i, j - 1});
        }
    }
    //for(Sta i : st[3])
        //cout << i.x << ' ' << i.y << endl;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            g[i][j] = 1e15;
    for(int i = 1; i <= m; ++i)
        for(Sta j : st[i])
            for(Sta k : st[i])
                g[j.x][k.x] = min(g[j.x][k.x], t[j.x][j.y] + t[k.x][k.y]);
    int lim = 1e15;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(g[i][j] < lim) e[i].push_back({j, g[i][j]});
    for(int i = 1; i <= n; ++i)
        dijkstra(i, dis[i]);
    while(q--) {
        int x, y;
        cin >> x >> y;
        int ans = 1e15;
        for(Sta i : st[x]) {
            for(Sta j : st[y]) {
                int tot = dis[i.x][j.x] + w[x] + w[y] + t[i.x][i.y] + t[j.x][j.y];
                if(ans < tot) {
                    //cout << x << ' ' << y << '\n';
                    //cout << i.x << ' ' << i.y + 1 << '\n';
                    //cout << j.x << ' ' << j.y + 1 << '\n';
                    //cout << w[x] + t[i.x][i.y] << '\n';
                    //cout << w[y] + t[j.x][j.y] << '\n';
                    //cout << tot << endl;
                    ans = min(ans, tot);
                }
                ans = min(ans, tot);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
