#include<bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 20;
const int maxn = 520;
vector<int> station[maxm];
long long c, n, m, d, q, w[maxm], k[maxn], t[maxn][maxm], dis[maxn][maxn];
long long solve(int x, int y){
    long long ans = LLONG_MAX;
    for(int i = 0; i < (int)station[x].size(); i++){
        for(int j = 0; j <= (int)station[y].size(); j++){
            int start_line = station[x][i];
            int end_line = station[y][j];
            ans = min(ans, dis[start_line][end_line] + t[start_line][x] + t[end_line][y]);
        }
    }
    return ans + w[x] + w[y];
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x7f, sizeof(dis));
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            int x; cin >> x;
            cin >> t[i][x];
            station[x].push_back(i);
        }
    }
    for(int a = 1; a <= m; a++)
        for(int i = 0; i < (int)station[a].size(); i++)
            for(int j = 0; j < (int)station[a].size(); j++){
                if(i == j) continue;
                int x = station[a][i];
                int y = station[a][j];
                dis[y][x] = dis[x][y] = min(dis[x][y], t[x][a] + t[y][a]);
            }
    for(int z = 1; z <= n; z++)
        for(int x = 1; x <= n; x++)
            for(int y = 1; y <= n; y++){
                if(x == y) continue;
                if(dis[x][z] >= 0x7f7f7f7f7f7f7f7f) continue;
                if(dis[z][y] >= 0x7f7f7f7f7f7f7f7f) continue;
                dis[x][y] = min(dis[x][y], dis[x][z] + dis[z][y]);
            }
    while(q--){
        int x, y; cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}
