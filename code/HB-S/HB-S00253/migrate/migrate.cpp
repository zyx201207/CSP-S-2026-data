#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t > 0){
        int n,d;
        cin >> n >> d;
        int dis[505][505];
        memset(dis,0x3f,sizeof(dis));
        int x[5005];
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(abs(x[i]-x[j]) <= d){
                    dis[i][j] = 1;
                }
            }
        }
        int cnt = 0;
        bool vis[505][505] = {0};
        int res[505][505] = {0};
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    if(dis[i][j] > dis[i][k]+dis[k][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                        if(vis[i][j] == 1 || vis[j][i] == 1){
                            cnt--;
                            vis[i][j] = 0;
                            res[i][j] = 0;
                            res[j][i] = 0;
                            // cout << i << " " << k << " " << j << endl;
                        }
                    }
                    if(i != j && vis[j][i] == 0 && vis[i][j] == 0 && dis[i][j] == dis[i][k]+dis[k][j]){
                        vis[i][j] = 1;
                        // cout << i << " " << k << " " << j << endl;
                        cnt++;
                        res[i][j]++;
                        res[j][i]++;
                    }
                    if(res[i][j] > 2 || res[j][i] > 2){
                        cnt -= 2;
                        vis[i][j] = 0;
                        res[i][j] = 0;
                        res[j][i] = 0;
                    }
                }
            }
        }
        cout << cnt << endl;
        t--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}