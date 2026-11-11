#include<bits/stdc++.h>
using namespace std;

struct node{
    long long to, val;
};
vector<node> adj[100010];
long long c, n, m, d, q, cnt, t, a, b, st, en, w[600], dist[100010];

void dfs(int x){
    for(node y :adj[x]){
        if(dist[x] + y.val < dist[y.to]){
            dist[y.to] = dist[x] + y.val;
            dfs(y.to);
        }
    }
    return ;
}


int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    cnt = m;
    for(long long i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(long long i = 1; i <= n; i++){
        cin >> t;
        cin >> a >> b;
        cnt++;
        adj[a].push_back({cnt, b});
        adj[cnt].push_back({a, b});
        for(long long i = 2; i <= t; i++){
            cin >> a >> b;
            cnt++;
            adj[a].push_back({cnt, b});
            adj[cnt].push_back({a, b});
            adj[cnt].push_back({cnt - 1, 0});
            adj[cnt - 1].push_back({cnt, 0});
        }
    }
    for(long long i = 1; i <= q; i++){
        for(long long i = 1; i <= cnt; i++){
            dist[i] = LLONG_MAX;
        }
        cin >> st >> en;
        dist[st] = 0;
        dfs(st);
        cout << dist[en] + w[st] + w[en] << '\n';
    }
    return 0;
}