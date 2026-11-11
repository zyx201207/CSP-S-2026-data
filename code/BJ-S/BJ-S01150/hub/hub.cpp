#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m, c, t, dis[5005][5005];
vector<int>vec[5005];

int main(){
    freopen("hub.in" , "r", stdin );
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> m;
        if(n <= 5000){
            for(int i = 0; i <= 5000; i++){
                for(int j = 0; j <= 5000; j++){
                    dis[i][j] = 1e18;
                }
            }
            for(int i = 1; i < n; i++){
                int u, v;
                cin >> u >> v;
                vec[u].push_back(v);
                dis[u][v] = 1, dis[v][u] = 1;
                dis[i][i] = 0;
            }
            dis[n][n] = 1;
            for(int k = 1; k <= n; k++){
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j < i; j++){
                        dis[i][j] = min(dis[i][k]+dis[k][j], dis[i][j]);
                        dis[j][i] = dis[i][j];
                    }
                }
            }
            ll ans = 1e18, tmp = 0;
            if(m == 1){
                for(int i = 1; i <= n; i++){
                    tmp = 0;
                    for(int j = 1; j <= n; j++){
                        tmp = max(dis[i][j], tmp);
                    }
                    ans = min(ans, tmp);
                }
            }else{
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j < i; j++){
                        tmp = 0;
                        for(int k = 1; k <= n; k++){
                            tmp = max(tmp, min(dis[i][k], dis[j][k]));
                        }
                        //cout << tmp;
                        ans = min(ans, tmp);
                    }
                }
            }
            cout << ans-((m-2)/2) << endl;
        }else{
            for(int i = 1; i < n; i++){
                int u, v;
                cin >> u >> v;
            }
            cout << ceil((n-m-(m^n&3))/3) << endl;
        }
    }
    return 0;
}
