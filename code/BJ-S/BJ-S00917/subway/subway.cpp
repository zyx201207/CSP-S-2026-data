#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 1e3 + 7;
int c, n, m, d, q;
LL dis[N][N], w[N];
struct Edge {
    int y;
    LL w;
};
vector<Edge> e[N];
struct node {
    int to;
    LL dis;
    bool operator < (const node &B) const {
        return dis > B.dis;
    }
};
void dijkstra(int s, LL dis[]) {
    priority_queue<node> q;
    q.push({s, 0});
    dis[s] = 0;
    while(!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if(d > dis[x]) continue;
        for(auto [y, w] : e[x]) {
            if(dis[x] + w >= dis[y]) continue;
            dis[y] = dis[x] + w;
            q.push({y, dis[y]});
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++)
        scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++) {
        int K;
        scanf("%d", &K);
        vector<LL> a(K + 1), t(K + 1);
        for(int j = 1; j <= K; j++)
            scanf("%lld%lld", &a[j], &t[j]);
        for(int j = 1; j <= K; j++)
            for(int k = j + 1; k <= K; k++) {
                e[a[j]].push_back({a[k], t[j] + t[k]});
                e[a[k]].push_back({a[j], t[j] + t[k]});
            }
    }
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= m; i++)
        dijkstra(i, dis[i]);
    while(q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        cout << w[x] + dis[x][y] + w[y] << '\n';
    }
    return 0;
}
