#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

struct edge{
    int v,w;
};

int c,n,m,d,q;
int k,x,y;
vector<edge> stage[500010];
int w[500010];
int dis[510][510];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++){
        cin >> w[i];
    }
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1;i <= n;i++){
        cin >> k;
        dis[i][i] = 0;
        for (int j = 1;j <= k;j++){
            cin >> x >> y;
            stage[x].push_back({i,y});
        }
    }
    for (int i = 1;i <= m;i++){
        for (int j = 0;j < stage[i].size();j++){
            for (int l = j+1;l < stage[i].size();l++){
                dis[stage[i][j].v][stage[i][l].v] = min(dis[stage[i][j].v][stage[i][l].v],stage[i][j].w + stage[i][l].w);
                dis[stage[i][l].v][stage[i][j].v] = min(dis[stage[i][l].v][stage[i][j].v],stage[i][j].w + stage[i][l].w);
            }
        }
    }
    for (int p = 1;p <= n;p++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++){
                dis[i][j] = min(dis[i][j],dis[i][p]+dis[p][j]);
            }
        }
    }
    //for (int i = 1;i <= n;i++){
    //    for (int j = 1;j <= n;j++){
    //        cout << dis[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    while (q--){
        cin >> x >> y;
        int ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0;i < stage[x].size();i++){
            for (int j = 0;j < stage[y].size();j++){
                int s1 = stage[x][i].v,s2 = stage[y][j].v;
                ans = min(ans,stage[x][i].w + stage[y][j].w + dis[s1][s2]);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
