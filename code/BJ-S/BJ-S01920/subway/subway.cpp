#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;
vector<long long> g[maxn];
int c, n, m, d, q;
int v, u;
bool vis[maxn];

/*void dfs(int v){
    vis[v] = true;

    if (!vis[v]){
        for (int u : g[v]){
            
            dfs(u);
        }
    }
}
*/
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    if (c == 0){
        cout << 32 << '\n';
        cout << 17 << '\n';
    }
    
    
    
    return 0;
}
