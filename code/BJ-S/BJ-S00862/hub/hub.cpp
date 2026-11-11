#include<bits/stdc++.h>
using namespace std;

long long c, t, n, k, u, v, ans = LLONG_MAX, dist, vis[1001], vv[1001];
vector<long long> adj[1001];

void dfslt(long long x){
    vv[x] = 1;
    for(long long y : adj[x]){
        if(!vv[y] && vis[y]){
            dfslt(y);
        }
    }
}

void dfsd(long long x, long long cost){
    vv[x] = 1;
    if(vis[x]){
        dist = min(dist, cost);
        return ;
    }
    for(long long y : adj[x]){
        if(vv[y]){
            continue;
        }
        dfsd(y, cost + 1);
    }
}

bool lt(){
    long long ccnt = 0;
    memset(vv, 0, sizeof(vv));
    for(long long i = 1; i <= n; i++){
        if(!vis[i]){
            continue;
        }
        if(vv[i]){
            continue;
        }
        dfslt(i);
        ccnt++;
    }
    if(ccnt > 2){
        return 0;
    }
    return 1;
}

long long d(long long x){
    dist = LLONG_MAX;
    memset(vv, 0, sizeof(vv));
    dfsd(x, 0);
    return dist;
}

long long cost(){
    long long res = 0;
    if(!lt()){
        return LLONG_MAX;
    }
    else{
        for(long long i = 1; i <= n; i++){
            res = max(res, d(i));
        }
        return res;
    }
}

void dfs(long long x, long long ch){
    if(ch == k){
        ans = min(ans, cost());
    }
    if(x == n){
        return ;
    }
    else{
        vis[x + 1] = 1;
        dfs(x + 1, ch + 1);
        vis[x + 1] = 0;
        dfs(x + 1, ch);
    }
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }
        ans = LLONG_MAX;
        for(long long i = 1; i < n; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, 0);
        cout << ans << '\n';
    }
    return 0;
}