#include<bits/stdc++.h>
using namespace std;
struct node{
    int N, K;
};
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q, w[500005], t[500005];
    set<int> k[500005];
    vector<node> adj[500005];
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        int kk;
        cin >> kk;
        for(int j = 1; j <= kk * 2; j++){
            if(i % 2 == 1){
                int l;
                cin >> l;
                k[i / 2 + 1].incert(l);
                adj[k[i / 2]].push_back({k[i / 2 + 1], 0});
            }
            else cin >> t[i][j / 2];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int o = 1; o <= k[i].size(); o++){
              if(k[i].find(o) && k[j].find(o)) adj[o].push_back({o, t[i][o] + t[j][o]});
            }
        }
    }
    for(int i = 1; i <= r; i++){
        int s, e, ans = 0, minn = INT_MAX, dp;
        cin >> s >> e;
        ans += w[s] + w[e];
        int dis[500005];
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while(q.size()){
            int u = q.front(); q.pop();
            for(int v : adj[u].N){
                if(!vis[v]){
                    q.push(v);
                    dis[v] = dis[u] + adj[u].K;
                    vis[v] = 1;
                }
            }   
        } 
        cout << dis[t] + w[i] + w[j];
    }
}
