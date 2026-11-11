#include <bits/stdc++.h>
using namespace std;

#define ll long long

int c, t, n;
ll d;
ll x[5006];
int dis[5006][5006], cnt[5006][5006];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        memset(dis,0x3f,sizeof dis);
        memset(cnt,0,sizeof cnt);
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            dis[i][i] = 0;
            cnt[i][i] = 1;
            for(int j = 1;j <= n;j++){
                if(cnt[i][j]==2)ans++;
                if(cnt[i][j]==0)continue;
                for(int k = i+1;k <= n;k++){
                    if(x[k]-x[i] > d)break;
                    if(dis[i][j]+1 < dis[k][j]){
                        dis[k][j] = dis[i][j]+1;
                        cnt[k][j] = cnt[i][j];
                    }
                    else if(dis[i][j]+1==dis[k][j]){
                        cnt[k][j]+=cnt[i][j];
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
