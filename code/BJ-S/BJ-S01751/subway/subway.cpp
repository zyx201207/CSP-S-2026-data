#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ww[500005];
long long dis[505][505];
vector<pair<int,int> > bb[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> ww[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        while(k--){
            int a,t;
            cin >> a >> t;
            bb[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= n;i++){
        dis[i][i] = 0;
    }
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < bb[i].size();j++){
            for(int k = j + 1;k < bb[i].size();k++){
                int t1 = bb[i][j].first;
                int t2 = bb[i][k].first;
                dis[t1][t2] = dis[t2][t1] = min(dis[t1][t2],(long long)bb[i][j].second + bb[i][k].second);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                dis[j][k] = min(dis[j][k],dis[j][i] + dis[i][k]);
            }
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        long long ans = 1e18;
        for(int i = 0;i < bb[x].size();i++){
            for(int j = 0;j < bb[y].size();j++){
                int t1 = bb[x][i].first;
                int t2 = bb[y][j].first;
                ans = min(ans,bb[x][i].second + bb[y][j].second + dis[t1][t2]);
            }
        }
        cout << ans + ww[x] + ww[y] << '\n';
    }
    return 0;
}
