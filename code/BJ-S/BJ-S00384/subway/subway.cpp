#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[125255];
vector<pair<int, int> > v[125255];
int vis[500][500];
void dfs(int start, int now, int t, int y){
    for(auto x : v[now]){
        int add = 0;
        if(x.second != y){
            add = vis[now][x.second];
        }
        if(vis[start][x.first] == 0 || vis[start][x.first] > vis[now][x.first] + t + add){
            vis[start][x.first] = vis[now][x.first] + t + add;
            vis[x.first][start] = vis[now][x.first] + t + add;
            dfs(start, x.first, vis[now][x.first] + t + add, x.second);
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 0; i < m; i++){
        cin >> w[i];
    }
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        int xx, yy, t;
        cin >> xx;
        for(int j = 1; j < k; j++){
            cin >> yy >> t;
            v[xx].push_back({xx, i});
            v[yy].push_back({yy, i});
            vis[xx][yy] = t;
            vis[yy][xx] = t;
            xx = yy;
        }
    }
    for(int i = 0; i < n; i++){
        dfs(i, i, 0, -1);
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        cout << w[x] + w[y] + vis[x][y] << "\n";
    }
    return 0;
}
