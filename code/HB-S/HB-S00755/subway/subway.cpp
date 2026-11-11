#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rd read()
#define pii pair<ll,ll>
#define fo(a,b,c) for(int a=(b); a<=(c);++a)
#define of(a,b,c) for(int a=(b); a<=(c);--a)
const int N =5e5+7, M = 1e5+7, INF = 0x3f3f3f3f;
inline int read() {
    int x = 0,f=1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-')f=-1; ch = getchar();}
    while (ch >='0' && ch <='9') {x=x*10+ch-'0';ch = getchar();}
    return x*f;
}
// g++ subway.cpp -o subway -std=c++14 -O2 -Wall

struct plan{
    int x, y;
}que[M];
int c, n, m, d, q;
vector<pii> g[N*3];
void Input() {
    c = rd, n = rd, m = rd, d = rd, q = rd;
    fo (i, 1, m) {
        int w = rd;
        g[i].push_back({i+m, w});
        g[i+m].push_back({i, w});
    }
    fo (i, 1, n) {
        int k = rd;
        fo (j, 1, k) {
            int a, t;
            a = rd;
            t = rd;
            g[a+m].push_back({i+2*m, t});
            g[i+2*m].push_back({a+m, t});
        }
    }
    fo (i, 1, q) {
        que[i] = {rd, rd};
    }
}
// i: subway
// i+n: ting
// i+2*n: tai
ll vis[N*3], dis[N*3];
void dij(int st) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dis[st], st});
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto e:g[u]) {
            ll v = e.first, w = e.second;
            if (dis[v] > dis[u]+w) {
                dis[v] = dis[u]+w;
                pq.push({dis[v], v});
            }
        }
    }
}
void answer() {

}
void solve() {
    Input();
    fo (i, 1, q) {
        dij(que[i].x);
        printf("%lld\n", dis[que[i].y]);
    }
    answer();
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    solve();
    return 0;
}