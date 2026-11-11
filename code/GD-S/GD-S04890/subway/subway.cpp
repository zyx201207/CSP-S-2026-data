#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    int to, v;
};
const int maxn = 5e5 + 10;
vector<int> a[maxn];
vector<edge> g[30];
int w[maxn], t[520][maxn], vis[520];
ll ans = 1e12 + 10;
void dfs(int x, int y, ll sum){
    if(x == y){
        ans = min(ans, sum);
        //cout << "dao\n";
        return ;
    }
    for(auto it : g[x]){
        if(vis[it.to] != 0) continue;
        vis[it.to] = 1;
        //cout << it.v << '\n';
        dfs(it.to, y, sum + it.v);
        vis[it.to] = 0;
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int c;
    while(cin >> c){
        int n, m, d, q;
        cin >> n >> m >> d >> q;
        for(int i = 1; i <= 20; i++) g[i].clear();
        for(int i = 1; i <= m; i++) a[i].clear();
        for(int i = 1; i <= m; i++) cin >> w[i];
        for(int i = 1; i <= n; i++){
            int k;
            cin >> k;
            for(int j = 1; j <= k; j++){
                int tmp;
                cin >> tmp >> t[i][j];
                a[tmp].push_back(i);
            }
        }
        for(int i = 1; i <= m; i++){
            if(a[i].size() > 1){
                for(int j = 0; j < a[i].size(); j++){
                    for(int z = j + 1; z < a[i].size(); z++){
                        int val = t[a[i][j]][i] + t[a[i][z]][i];
                        g[a[i][j]].push_back({a[i][z], val});
                        g[a[i][z]].push_back({a[i][j], val});
                    }
                }
            }
        }
        while(q--){
            int x, y;
            cin >> x >> y;
            ll mn = 1e12 + 10;
            for(int it1 : a[x]){
                for(int it2 : a[y]){
                    ans = 1e12 + 10;
                    memset(vis, 0, sizeof(vis));
                    dfs(it1, it2, 0);
                    cout << ans;
                    ans += w[x] + w[y] + t[it1][x] + t[it2][y];
                    mn = min(mn, ans);
                }
            }
            //cout << mn << '\n';
        }
    }
    return 0;
}

