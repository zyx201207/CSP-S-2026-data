#include <bits/stdc++.h>
using namespace std;

//Oct31==Dec25?
typedef long long ll;
const int N = 5e5+10;
//地铁口->站厅->站台->站厅->站台->站厅->地铁口
ll n, m, d, q;
ll w[N];        //第i个地铁口到站厅
ll t[505][505]; //第i个地铁站站厅到第j条线路的站台
ll a[505][505];
ll g[505][505][30];
vector <ll> f[N];
ll sss[505];
int main(){
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int c;  cin >> c;
    cin >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    for(int i = 1;i <= n;i++){
        int k;  cin >> k;
        ll pu = 0;
        for(int j = 1;j <= k;j++){
            ll u;   cin >> u;
            if(j != 1)  a[pu][u] = a[u][pu] = 1;
            pu = u;
            f[u].push_back(i);
            ll w;   cin >> w;   t[u][i] = w;
        }
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            for(int k = 1;k <= 21;k++)
                if(i != j)  g[i][j][k] = 1e18;
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(i != j && j != k && i != k)a[i][j] = ((a[i][k] & a[k][j]) | a[i][j]);
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int l = 1;l <= d;l++){
                    if((i != j && j != k && i != k) && a[i][k] && a[k][j] && t[k][l] && t[j][l]){
                        for(auto vv : f[i]){
                            if(t[k][vv] && vv != i)
                                g[i][j][l] = min(g[i][j][l], (ll)(g[i][k][vv]+g[k][j][l]+t[k][l]+t[j][l]));

                        }
                    }


                }
            }
        }
    }
    while(q--){
        ll u, v;    cin >> u >> v;
        ll ans = 1e18;
        for(int i = 1;i <= 20;i++) ans = min(g[u][v][i], ans);
        cout << ans << '\n';
    }
    return 0;
}
