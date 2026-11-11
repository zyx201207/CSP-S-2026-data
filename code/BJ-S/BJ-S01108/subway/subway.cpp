#include<bits/stdc++.h>
using namespace std;
const int M = 5e3+5;
const int INF =0x3f3f3f3f;
int c, n, m, d, q;
int dist[M][M];
int w[M];
void floyd(){
    for(int k = 1; k<=m; k++){
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1; i<=m; i++)cin >> w[i];
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            dist[i][j]=INF;
        }
    }
    for(int i=1; i<=m; i++){
        dist[i][i]=0;
    }
    for(int i=1; i<=n; i++){
        int k;
        cin >> k;
        vector<pair<int, int>>pli;
        for(int j=1; j<=k; j++){
            int x, t;
            cin >> x >> t;
            pli.push_back({x, t});
        }
        for(int j=1; j<=k; j++){
            int station = pli[j-1].first;
            for(int p=j+1; p<=k; p++){
                dist[station][pli[p-1].first] = pli[j-1].second + pli[p-1].second;
                dist[pli[p-1].first][station] = pli[j-1].second + pli[p-1].second;
                //cout << station <<" " <<pli[p-1].first << " " << dist[station][pli[p-1].first] << endl;
            }
        }
    }
    floyd();
    while(q--){
        int x, y;
        cin >> x >> y;
        long long ans = w[x] + w[y] +dist[x][y];
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
