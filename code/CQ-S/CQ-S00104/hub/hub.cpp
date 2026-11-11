//Change's Code
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int> > tu(n+1);
        for(int i=1;i<n;i++){
            int u, v;
            cin >> u >> v;
            tu[u].push_back(v);
            tu[v].push_back(u);
        }
        int ans2 = 1e9;
        for(int mask=0;mask<(1<<n);mask++){
            if(__builtin_popcount(mask) == k){
                auto lowbit = [](int x){
                    return x & -x;
                };
                bool zt = 1;
                auto check = [&mask](int x)->bool {
                    return ((mask >> x-1) & 1);
                };
                struct DSU{
                    vector<int> fa;
                    DSU(int x){
                        fa.resize(x+1);
                        for(int i=1;i<=x;i++) fa[i] = i;
                    }
                    int getfa(int x){
                        return (fa[x] == x) ? x : fa[x] = getfa(fa[x]);
                    }
                    void merge(int x, int y){
                        int fx = getfa(x);
                        int fy = getfa(y);
                        if(fx != fy){
                            fa[fy] = fx;
                        }
                    }
                }dsu(n);
                set<int> js;
                for(int i=1;i<=n;i++){
                    if(check(i)){
                        for(int v : tu[i]){
                            if(check(v)) dsu.merge(i, v);
                        }
                    }
                }
                for(int i=1;i<=n;i++){
                    if(check(i)){
                        js.insert(dsu.getfa(i));
                    }
                }
                if(js.size() <= 2){
                    int ans = 0;
                    vector<int> f(n+1, 1e9);
                    for(int i=1;i<=n;i++){
                        if((mask >> i-1) & 1){
                            auto dfs = [&f, &tu, &mask](auto &&self, int u, int fa)->void {
                                if((mask >> u-1) & 1) f[u] = 0;
                                for(int v : tu[u]){
                                    if(v == fa) continue;
                                    f[v] = min(f[v], f[u]+1);
                                    self(self, v, u);
                                }
                            };
                            dfs(dfs, i, -1);
                            while((mask >> i-1) & 1) i++;
                            i --;
                        }
                    }
                    for(int i=1;i<=n;i++) ans = max(ans, f[i]);
                    ans2 = min(ans2, ans);
                }
            }
        }
        printf("%d\n", ans2);
    }
    return 0;
}