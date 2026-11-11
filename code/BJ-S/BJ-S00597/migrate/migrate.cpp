#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 300 + 5;
int c, t, n, d, a[N], dis[N][N], us[N][N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;
    while(t--){
        memset(dis, 0x3f, sizeof dis);
        memset(us, 0, sizeof us);
        cin >> n >> d;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(abs(a[i] - a[j]) <= d) dis[i][j] = 1;
            }
        }
        int ans = 0;
        for(int k = 1;k <= n;k++){
            for(int i = 1;i <= n;i++){
                if(i == k) continue;
                for(int j = 1;j < i;j++){
                    if(j == k) continue;
                    if(dis[i][j] > dis[i][k] + dis[k][j]){
                        if(us[i][j]) us[i][j] = us[j][i] = 0;
                        dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
                    } else if(dis[i][j] == dis[i][k] + dis[k][j]) us[i][j] = us[j][i] = 1;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(us[i][j]) ans++;
            }
        }
        cout << ans/2 << '\n';
    }
    return 0;
}
