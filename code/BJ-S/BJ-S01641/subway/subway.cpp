#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],dis[505][505];
vector<pair<int,int> > e[500005];
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for (int j = 1;j <= k;j++){
            int a,t;
            cin >> a >> t;
            e[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1;i <= n;i++) dis[i][i] = 0;
    for (int i = 1;i <= m;i++) for (int j = 0;j < e[i].size();j++) for (int k = j + 1;k < e[i].size();k++) dis[e[i][j].first][e[i][k].first] = dis[e[i][k].first][e[i][j].first] = e[i][j].second + e[i][k].second;
    for (int k = 1;k <= n;k++) for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    while (q--){
        int x,y,ans = LONG_LONG_MAX;
        cin >> x >> y;
        for (int i = 0;i < e[x].size();i++) for (int j = 0;j < e[y].size();j++) ans = min(ans,e[x][i].second + e[y][j].second + dis[e[x][i].first][e[y][j].first]);
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}