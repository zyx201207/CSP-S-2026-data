#include<bits/stdc++.h>
#define pii pair<int, int>
#define int long long
using namespace std;

// index:
// 1~m: entrance
// m+1 ~ 2m: hall
// >2m: station(using vector)
const int N = 5e5 + 20, inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
int W[N];
vector<pair<int, int>> H[N]; // H[i]: indexes & dist of node i's stations
vector<vector<int>> L; //subway lines
vector<pair<int, int>> G[N];

vector<vector<int>> dij(int cnt){
    vector<vector<int>> res;

    for(int s = 1; s < cnt; ++s){
        vector<int> dist(cnt, inf);
        vector<bool> vis(cnt);
        priority_queue<pii, vector<pii>, less<pii>> Q;

        dist[s] = 0, Q.push({0, s});
        while(!Q.empty()){
            auto[w, u] = Q.top(); Q.pop();
            if(vis[u]) continue;
            if(w > dist[u]) continue;
            vis[u] = true;
            for(auto[v, w1] : G[u]){
                if(dist[v] > dist[u] + w1){
                    dist[v] = dist[u] + w1;
                    Q.push({dist[v], v});
                }
            }
        }
        res.push_back(dist);
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) cin >> W[i];

    int cnt = m + 1;

    L.push_back(vector<int>());
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        L.push_back(vector<int>());
        for(int j = 1; j <= k; ++j){
            int a, t; cin >> a >> t;
            H[a].push_back({cnt, t});
            L[i].push_back(cnt);
            ++cnt;
        }
    }
    vector<vector<int>> dist(cnt, vector<int>(cnt, inf));
    for(auto tmp : L){
        for(int i = 1; i < tmp.size(); ++i)
            dist[tmp[i]][tmp[i - 1]] = dist[tmp[i - 1]][tmp[i]] = 0;
    }
    for(int i = 1; i <= m; ++i){
        for(auto [j, w] : H[i])
            dist[i][j] = dist[j][i] = w;
    }
    for(int i = 1; i < cnt; ++i) for(int j = 1; j < cnt; ++j){
        if(dist[i][j] != inf) G[i].push_back({j, dist[i][j]});
    }

//    for(int i = 1; i < cnt; ++i){
//        for(int j = 1; j < cnt; ++j){
//            if((dist[i][j] == inf)) cout << "- ";
//            else cout << dist[i][j] << ' ';
//        }
//        cout << endl;
//    }

    auto res = dij(cnt);
    while(q--){
        int x, y; cin >> x >> y;
        cout << res[x - 1][y] + W[x] + W[y] << endl;
    }
    return 0;
}
