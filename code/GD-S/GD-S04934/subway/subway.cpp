#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
const int N = 500 + 10;
const int Q = 1e5 + 10;
const long long INF = 1e18;

struct Node{
    int v, w;
};

int c, n, m, d, q;
int w[M], k[N];
vector<Node> edge[N + M];
long long dis[M + N];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
long long ans[Q];
int x[Q], y[Q];

void dij(int s){
    for(int i = 1; i <= m + n; i++)dis[i] = INF;
    pq.push({0, s + m});
    dis[m + s] = 0;
    while(!pq.empty()){
        auto [di, id] = pq.top();
        // cerr << s << " " << di << " " << id << "\n";
        pq.pop();
        if(dis[id] < di)continue;
        for(auto [v, w] : edge[id]){
            if(dis[v] > di + w){
                dis[v] = di + w;
                pq.push({di + w, v});
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1, v, w; j <= k[i]; j++){
            cin >> v >> w;
            edge[v].push_back({i + m, w});
            edge[i + m].push_back({v, w});
        }
    }
    for(int i = 1; i <= q; i++){
        ans[i] = INF;
        cin >> x[i] >> y[i];    
    }
    for(int i = 1; i <= n; i++){
        dij(i);
        for(int j = 1; j <= q; j++){
            ans[j] = min(ans[j], dis[x[j]] + dis[y[j]] + w[x[j]] + w[y[j]]);
        }
    }
    for(int i = 1; i <= q; i++)cout << ans[i] << "\n";
    return 0;
}