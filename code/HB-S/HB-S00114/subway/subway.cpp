#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, t;
int w[100000+10], vis[100000+10];
vector<int> G[100000+10];
int bfs(int x, int y) {
    queue<pair<int, int>> q;
    vis[x] = 1;
    q.push({x, 0});
    while(!q.empty()) {
        pair<int, int> Q;
        int z1 = Q.first, z2 = Q.second;
        if(z2 ==  y) {
            return z2;
        }
        for(int i : G[z1]) {
            if(vis[i] != 1) {
                vis[i] = 0;
                q.push({i, z2+1});
            }
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;
    if(c >= 12 && c <= 19) {
        for(int i = 1;i<=m;i++) cin >> w[i];
        for(int i = 1;i<=n;i++) {
            int k;cin>>k;cin>>t;
            for(int j = 1;j<=k;j++) {
                int m;cin>>m;
                G[i].push_back(m);
                G[m].push_back(i);
            }
        }
        for(int i = 1;i<=q;i++) {
            int x, y;cin>>x>>y;
            cout << bfs(x, y) * (t+w[i]) << "\n";
        }
    }
    return 0;
}
