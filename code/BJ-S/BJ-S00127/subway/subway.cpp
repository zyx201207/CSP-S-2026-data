#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int M = 2e4+5, N = 505;
ll c, n, m, d, q;
ll w[M], a[M], t[M], k, x, y;
int g[M][M];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            g[i][j] = g[j][i] = 8e5+5;
        }
    }
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> a[j] >> t[j];
            for(int x = 1; x <= k; x++){
                if(a[x] == a[j]) g[a[x]][a[j]] = g[a[j]][a[x]] = 0;
                else{
                    g[a[x]][a[j]] = g[a[j]][a[x]] = t[j] + t[x];
                }
            }
        }
    }
    /*
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cout << g[i][j] << " ";
        }
        cout << '\n';
    }
    */
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= m; k++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                g[j][i] = g[i][j];
            }
        }
    }
    /*
    cout <<  '\n';
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cout << g[i][j] << " ";
        }
        cout << '\n';
    }
    */
    while(q--){
        cin >> x >> y;
        cout << g[x][y] + w[x] + w[y] << '\n';
        //cout << "g[x][y]:" << g[x][y] << '\n';
    }
    return 0;
}
