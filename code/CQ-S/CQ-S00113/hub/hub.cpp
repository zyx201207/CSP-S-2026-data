#include <bits/stdc++.h>
#define llong long long
#define N 105
using namespace std;

int n, k;
vector<int> G[N];
int dis[N];
int ark[N][N];

int fa[N];
inline int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int que[N], he, ta;

int _main(){
    cin >> n >> k;
    for(int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        ark[u][v] = ark[v][u] = true;
    }
    int ans = 1e9+7;
    for(int S = 0; S < (1<<n); ++S){
        vector<int> tmp;
        for(int i = 1; i <= n; ++i)
            if(S&(1<<i>>1)) tmp.push_back(i);
        int l = tmp.size();
        if(l != k) continue;
        for(int i = 1; i <= n; ++i) fa[i] = i;
        for(int i = 0; i < l; ++i){
            int u = tmp[i];
            for(int j = i+1; j < l; ++j){
                int v = tmp[j];
                if(ark[u][v]){
                    fa[find(u)] = find(v);
                }
            }
        }
        int cnt = 0;
        for(int i : tmp)
            if(find(i) == i) ++cnt;
        if(cnt > 2) continue;
        for(int i = 1; i <= n; ++i) dis[i] = -1;
        he = 1, ta = 0;
        for(int i : tmp) que[++ta] = i, dis[i] = 0;
        int res = 0;
        while(he <= ta){
            int u = que[he++];
            for(int v : G[u]){
                if(dis[v] != -1) continue;
                dis[v] = dis[u]+1, res = max(res, dis[v]);
                que[++ta] = v;
            }
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
    return 0;
}
void _init(){
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) ark[i][j] = 0;
    return;
}

int taskid, T;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> taskid >> T;
    while(T--) _init(), _main();
    return 0;
}

// 直到最后也没有实现 AK CSP 的愿望呢。
// 不挂分的话，100+100+100+15。
// 祝我好运。该去检查 freopen 了。 
// Oct.31 18:21
 
