#include <bits/stdc++.h>
using namespace std;
struct ed{
    int to,next,len;
}edge[500005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    int dis[505][505],w[500005];
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    int a[505][505],t[505][505],k[505];
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k[i];j++){
            for(int p = 1;p <= k[i];p++){
                dis[a[i][j]][a[i][p]] = min(t[i][p]+t[i][j],dis[a[i][j]][a[i][p]]);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            for(int p = 1;p <= k[i];p++){
                for(int o = 1;o <= k[j];o++){
                    dis[a[i][p]][a[j][o]] = min(t[i][p]+t[j][o],dis[a[i][p]][a[j][o]]);
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int u = 1;u <= n;u++){
                if(dis[i][j] > dis[i][u]+dis[u][j]){
                    dis[i][j] = dis[i][u] + dis[u][j];
                }
            }
        }
    }
    for(int i = 1;i <= q;i++){
        int x,y;
        cin >> x >> y;
        cout << dis[x][y]+w[x]+w[y] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}