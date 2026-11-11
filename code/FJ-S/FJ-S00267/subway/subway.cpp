#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int maxm = 5e5 + 5;
const int maxn = 1e7 + 5; 

struct node {
    int dis, v;
    bool operator<(node o) const {
        return dis > o.dis;
    }
};

int c, n, m, d, q, tot;
int a[maxm], dis[maxn], dis2[maxn], vis[maxn];
int dfn[maxn], low[maxn];
vector<pii> g[maxn];

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') {
            f = -1;   
        }
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + c - 48;
        c = getchar();
    }
    return x * f;
}

void write(int x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x >= 10) {
        putchar(x / 10);
    }
    write(x % 10 + '0');
}

int id(int x, int y) {
    return m + (x - 1) * d + y;
}

void dij(int u) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[u] = 0;
    priority_queue<node> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        int u = pq.top().v;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (auto e : g[u]) {
            int v = e.fi, w = e.se;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

void dij2(int u) {
    memset(dis2, 0x3f, sizeof(dis2));
    memset(vis, 0, sizeof(vis));
    dis2[u] = 0;
    priority_queue<node> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        int u = pq.top().v;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (auto e : g[u]) {
            int v = e.fi, w = e.se;
            if (dis2[v] > dis2[u] + w) {
                dis2[v] = dis2[u] + w;
                pq.push({dis2[v], v});
            }
        }
    }
}

int main() {
	freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int ts = clock();
    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; ++i) {
        a[i] = read();
    }
    tot = m;
    for (int i = 1; i <= n; ++i) {
        int k, lst = 0;
        k = read();
        for (int j = 1; j <= k; ++j) {
            int u, w;
            u = read(), w = read();
            g[u].push_back({id(u, i), w});
            g[id(u, i)].push_back({u, w});
//            printf("%d - %d\n", u, id(u, i));
            if (lst == 0) {
                lst = id(u, i);
            } else {
                g[lst].push_back({id(u, i), 0});
                g[id(u, i)].push_back({lst, 0});
//                printf("%d - %d\n", lst, id(u, i));
            }
        }
    }
    dij(1);
    while (q--) {
        int st, ed;
        st = read(), ed = read();
        int te = clock();
        if (ts - te > 80) {
            cout << a[st] + a[ed] + abs(dis[st] - dis[ed]) << "\n"; 
        } else {
            dij2(st);
            cout << a[st] + a[ed] + abs(dis2[st] - dis2[ed]) << "\n"; 
        }       

    }
    return 0;
}   
/*
思路：
图论建模题
把每个点拆成d+1个点
然后建图
发现如果对于每一次的询问都跑dij，那么复杂度为qnlogn，会T
考虑优化
发现有环
那么直接点双缩点成圆方树，变成树上询问
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
