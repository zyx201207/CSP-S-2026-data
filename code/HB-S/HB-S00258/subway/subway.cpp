#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 10e5 + 5;

int c, n, m, d, q, w[N], k[N], a[N][501],t[501][N], x, y, z[501], vis[501];
vector<int> g[N];

int bfs(int cnt){
    queue<int> q;
    q.push(x);

    while(q.empty()) {
        int u = q.front();
        q.pop();

        
        for(const auto& v : g[u]) {
            if(vis[v] == 1) continue; 
            if(v == y) return z[v];
            vis[v] = 1;
            q.push(v);
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    if(c>=1 && c <= 6){
        for(int i = 1; i <= m; i++) cin >> w[i];

        for(int i = 1; i <= n; i++){
            cin >> k[i];
            for(int j = 1; j <= k[i]; j++) {
                cin >> a[i][j] >> t[i][j];
                g[a[i][j - 1]].push_back(a[i][j]);
            }
        } 
        while(q--) {
            cin >> x >> y;
            bfs(0);
        }
        return 0;
    }
    else if (1 == 1){
        
    }
}