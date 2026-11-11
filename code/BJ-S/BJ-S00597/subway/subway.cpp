
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505;
const int K = 1000 + 5;
struct Node{
    int v, w;
    friend bool operator <(Node x, Node y){
        return x.w > y.w;
    }
};
int c, n, m, d, q, w[N], dis[K][K];
vector<Node> g[K * N];

void dij(int s){
    priority_queue<Node> pq;
    pq.push({s, 0});
    dis[s][s] = 0;
    int vis[K * N] = {0};
    while(pq.size()){
        int u = pq.top().v;
        vis[u] = 1;
        pq.pop();
        for(auto [v, w] : g[u]){
            if(!vis[v] && dis[s][v] > dis[s][u] + w){
                dis[s][v] = dis[s][u] + w;
                pq.push({v, dis[s][v]});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    memset(dis, 0x3f, sizeof dis);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1, k, a, t;i <= n;i++){
        cin >> k;
        if(k == 1){
            cin >> a >> t;
            continue;
        } else {
            vector<pair<int, int>> e;
            while(k--){
                cin >> a >> t;
                e.push_back({a, t});
            }
            for(int j = 0;j < e.size();j++){
                if(j != 0){
                    g[e[j].first].push_back({e[j-1].first, e[j].second + e[j-1].second});
                    g[e[j-1].first].push_back({e[j].first, e[j].second + e[j-1].second});
                }
                if(j != e.size()-1){
                    g[e[j].first].push_back({e[j+1].first, e[j].second + e[j+1].second});
                    g[e[j+1].first].push_back({e[j].first, e[j].second + e[j+1].second});
                }
            }
        }
    }
    for(int i = 1;i <= m*n;i++) dij(i);
    while(q--){
        int x, y;
        cin >> x >> y;
        int ans = LLONG_MAX;
        for(int k = 0;k <= n;k++){
            for(int k2 = 0;k2 <= n;k2++){
                ans = min(ans, dis[x + m * k][y + m * k2]);
            }
        }
        cout << w[x] + ans + w[y] << '\n';
    }
    return 0;
}
