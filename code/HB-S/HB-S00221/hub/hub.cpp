#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 10, inf = 0x3f3f3f3f;

int C, T, n, K;
int e[N][N], vis[N], fa[N], book[N];
vector<int> g[N];

int popc(int x){
    return __builtin_popcount(x);
}

int getfa(int x){
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

void work(){
    cin >> n >> K;
    for(int i = 1; i <= n; i ++) g[i].clear();
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i != j) e[i][j] = inf;
            else e[i][j] = 0;
        }
    }
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        e[u][v] = e[v][u] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    int ans = inf;
    for(int S = 0; S < (1 << n); S ++){
        if(popc(S) != K) continue;
        for(int i = 1; i <= n; i ++) vis[i] = 0;
        for(int i = 0; i < n; i ++){
            if(S >> i & 1){
                vis[i + 1] = 1;
            }
        }
        //pan duan shi fou bu chao guo liang ge lian tong kuai
        for(int i = 1; i <= n; i ++) fa[i] = i;
        for(int i = 1; i <= n; i ++){
            if(!vis[i]) continue;
            for(auto v : g[i]){
                if(!vis[v]) continue;
                if(getfa(i) != getfa(v)){
                    fa[getfa(i)] = getfa(v);
                }
            }
        }

        int cnt = 0;
        for(int i = 1; i <= n; i ++) book[i] = 0;
        for(int i = 1; i <= n; i ++){
            if(!vis[i]) continue;
            if(!book[getfa(i)]){
                cnt++;
                book[getfa(i)] = 1;
            }
        }
        
        if(cnt > 2) continue;
        int res = 0;
        for(int i = 1; i <= n; i ++){
            int result = inf;
            for(int j = 1; j <= n; j ++){
                if(!vis[j]) continue;
                result = min(result, e[i][j]);
            }
            res = max(res, result);
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    
    cin >> C >> T;
    while(T--){
        work();
    }
    return 0;
}