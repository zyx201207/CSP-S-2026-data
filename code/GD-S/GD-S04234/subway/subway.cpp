#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct node{
    int des, tim;
};
vector<node> edge[N];
long long dist[N];
int w[N];
int c, n, m, d, q;
long long dijkstra(int s, int t){
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    set<pair<int, int>> q;
    for(int i = 1; i <= n; i++){
        q.insert({dist[i], i});
    }
    while(q.size()){
        int u = q.begin()->second;
        q.erase(q.begin());
        if(u == t||dist[u] > (1LL << 60)){
            break;
        }
        for(auto i : edge[u]){
            if(dist[u] + i.tim < dist[i.des]){
                q.erase({dist[i.des], i.des});
                dist[i.des] = dist[u] + i.tim;
                q.insert({dist[i.des], i.des});
            }
        }
    }
    if(dist[t] < (1LL << 60)){
        return dist[t];
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    long long point = m + 1;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        int lastp;
        for(int j = 1; j <= k; j++){
            int a, t;
            cin >> a >> t;
            edge[point].push_back({a, t});
            edge[a].push_back({point, t});
            if(j == 1){
                lastp = point;
            }else{
                edge[lastp].push_back({point, 0});
                edge[point].push_back({lastp, 0});
                lastp = point;
            }
            point++;
        }
    }
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        cout << dijkstra(x, y) + w[y] + w[x] << "\n";
    }
    return 0;
}
