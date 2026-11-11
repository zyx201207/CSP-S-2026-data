#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c, T, n, k, dep[N], L, rt;
vector<int>g[N];
void dfs(int u, int fa, int &rt){
    if(fa)dep[u] = dep[fa] + 1;
    else dep[u] = 0;
    if(dep[u] > dep[rt])rt = u;
    for(auto v : g[u]){
        if(v == fa)continue;
        dfs(v, u, rt);
    }
}
bool findrt(int u, int fa, int r1){
    bool flg = 0;
    for(auto v : g[u]){
        if(v == fa)continue;
        flg |= findrt(v, u, r1);
    }
    // cerr << u << " " << r1 << " " << flg << "\n";
    if(flg && dep[u] == L / 2)rt = u;
    return flg | (u == r1); 
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1;i <= n;i++)g[i].clear();
        for(int i = 1;i < n;i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }
        int rt0 = 0, rt1 = 0;
        dfs(1, 0, rt0);
        dfs(rt0, 0, rt1);
        L = dep[rt1];
        findrt(rt0, rt0, rt1);
        if(k == 2){
            int mx0 = 0, mx1 = 0, mx2 = 0;
            dep[rt] = 0;
            for(auto v : g[rt]){
                int nrt = 0;
                dfs(v, rt, nrt);
                // cerr << nrt << " " << dep[nrt] << "\n";
                int x = dep[nrt];
                if(x >= mx0)mx2 = mx1, mx1 = mx0, mx0 = x;
                else if(x >= mx1)mx2 = mx1, mx1 = x;
                else if(x > mx0)mx0 = x;
            }
            // cerr << mx0 << " " << mx1 << " " << mx2 << " " << rt0 << " " << rt1 << " " << rt << "\n";
            int ans = n + 1;
            for(int i = 0;i <= mx1;i++){
                ans = min(ans, max(mx1 - i, mx2 + i));
            }
            cout << ans << "\n";
        }else{
            cout << 1 << "\n";
        }
    }
    return 0;
}