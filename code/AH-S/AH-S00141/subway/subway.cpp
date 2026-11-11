#include<bits/stdc++.h>

using namespace std;
//rp++ 歪比巴卜
struct Info {
    int xian, t, to;
};

typedef long long ll;
ll c, n, m, d, q;
ll w[505];
vector<Info> edges[505];
int t[505][500005];

inline void bfs(int from, int to) {
    vector<int> dist(n + 1, -1), d(100005, 0), xia(100005, 0);
    int x = from, front = 0, rear = 1;
    dist[from] = 0;
    d[1] = x;
    while (true) {
        x = d[++front];
        for (auto y : edges[x]) {
            if (dist[y.to] == -1) {
                int z = 0;
                if (x != from && xia[front] != y.xian);
                    z = t[y.xian][x] + t[xia[front]][x];
                dist[y.to] = dist[x] + z + t[x][y.to], d[++rear] = y.to, xia[rear] = y.xian;
            }
            if (y.to == to) {
                cout << dist[y.to];
                return;
            }
        }
    }
}

int main() {
    //freopen("subway.in", "r", stdin);
    //freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1, last = 0; j <= k; j++) {
            int a, ti;
            cin >> a >> ti;
            if (j != 1) {
                Info x;
                x.t = ti;
                x.to = a;
                x.xian = i;
                edges[last].push_back(x);
            }
            t[last][a] = ti;
            last = a;
        }
    }
    for (; q--; ) {
        int from, to;
        cin >> from >> to;
        bfs(from, to);
    }
    return 0;
}
