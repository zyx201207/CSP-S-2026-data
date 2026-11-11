#include <iostream>
#include <algorithm>
using namespace std;
const int MAXM = 500005,MAXD = 25,MAXN = 505;
const long long inf = 1e18;
int C,n,m,d,Q,w[MAXM],tp[MAXM],id[MAXM][MAXD],t[MAXM][MAXD];
long long dis[MAXN][MAXN];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C >> n >> m >> d >> Q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        int K;
        cin >> K;
        while(K--){
            int x,y;
            cin >> x >> y;
            id[x][++tp[x]] = i;
            t[x][tp[x]] = y;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            dis[i][j] = ((i == j) ? 0 : inf);
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= tp[i];j++){
            for(int k = 1;k <= tp[i];k++){
                dis[id[i][j]][id[i][k]] = min(dis[id[i][j]][id[i][k]],(long long)(t[i][j] + t[i][k]));
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
    while(Q--){
        int x,y;
        cin >> x >> y;
        long long ans = inf;
        for(int i = 1;i <= tp[x];i++){
            for(int j = 1;j <= tp[y];j++){
                ans = min(ans,dis[id[x][i]][id[y][j]] + t[x][i] + t[y][j] + w[x] + w[y]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
