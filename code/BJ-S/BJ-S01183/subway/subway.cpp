#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500 + 10;
const int maxm = 5e5 + 10;
int c, n, m, d, q, w[maxm], k[maxm], dis[maxm];
bool vis[maxm];
struct node {
    int v, w;
};
vector<node> g[maxm*3];
vector<vector<int>> ans;
void dijkstra(int st) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, st});
    dis[st] = 0;
    while(!q.empty()) {
        pair<int, int> tp = q.top();
        q.pop();
        int x = tp.second;
        if(vis[x]) continue;
        vis[x] = true;
        for(node pr : g[x]) {
            int y = pr.v, w = pr.w;
            if(dis[y] <= dis[x] + w) continue;
            dis[y] = dis[x] + w;
            q.push({dis[y], y});
        }
    }
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
        g[i].push_back({i+m, w[i]});
        g[i+m].push_back({i, w[i]});
    }
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            int a, t;
            cin >> a >> t;
            g[m+a].push_back({2*m+i, t});
            g[2*m+i].push_back({m+a, t});
        }
    }
    if(9 <= c && c <= 11) {
        ans.resize(m+10, vector<int>(m+10, 0));
        for(int i = 1; i <= m; i++) {
            dijkstra(i);
            for(int j = 1; j <= m; j++) ans[i][j] = dis[j];
        }
    }
    int tmp = q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(9 <= c && c <= 11) {
            cout << ans[x][y] << "\n";
        } else {
            dijkstra(x);
            cout << dis[y] << "\n";
        }
    }
    return 0;
}