#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005];
long long dis[505][505];
vector<pair<int, int> >v[500005];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1;i <= m;i++) scanf("%d", &w[i]);
    for(int i = 1;i <= n;i++){
        int k, a, t;
        scanf("%d", &k);
        while(k--) scanf("%d%d", &a, &t), v[a].push_back({i, t});
    }
    memset(dis, 0x1f, sizeof(dis));
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < v[i].size();j++){
            int x = v[i][j].first, t1 = v[i][j].second;
            for(int k = j + 1;k < v[i].size();k++){
                int y = v[i][k].first, t2 = v[i][k].second;
                dis[x][y] = min(dis[x][y], (long long)t1 + t2);
                dis[y][x] = min(dis[y][x], (long long)t1 + t2);
            }
        }
    }
    for(int i = 1;i <= n;i++) dis[i][i] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                if(dis[j][k] > (long long)dis[j][i] + dis[i][k]){
                    dis[j][k] = dis[j][i] + dis[i][k];
                    dis[k][j] = dis[j][i] + dis[i][k];
                }
            }
        }
    }
    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);
        long long ans = 1e18;
        for(pair<int, int> p1:v[x]){
            for(pair<int, int> p2:v[y]){
                long long t = (long long)p1.second + (long long)p2.second;
                ans = min(ans, dis[p1.first][p2.first] + t);
            }
        }
        printf("%lld\n", ans + (long long)w[x] + (long long)w[y]);
    }
    return 0;
}
