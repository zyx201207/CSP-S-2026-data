#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
struct Graph{
    int to,l;
};
vector<Graph> g[1005];
vector<int> v[505],u[505];
int w[N],f[1005][1005],k[505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >>n >> m >> d >> q;
    for (int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++){
            cin >> k[i];
        for (int j = 1;j <= k[i];j++){
            int s,t;cin >> s >> t;
            u[i].push_back(t);
            v[i].push_back(s);
        }
    }
    for (int i = 1;i <= n;i++){
        for (int j = 0;j <= k[i] - 1;j++){
            for (int l = j + 1;l <= k[i] - 1;l++){
                    int d = v[j][l];
                g[j].push_back({d,u[i][j] + u[i][d]});
                g[d].push_back({j,u[i][j] + u[i][d]});
            }
        }
    }
    for (int i = 1;i <= m;i++){
        for (int j = 1;j <= m;j++){
            for (int k = 0;k <= g[j].size() - 1;k++){
                f[i][g[j][k].to] = min(f[i][g[j][k].to],f[i][j] +g[j][k].l);
            }
        }
    }
    for (int i = 1;i <= q;i++){
        int s,t;
        cin >> s >> t;
        cout << f[s][t] + w[s] + w[t] << endl;
    }
    return 0;
}
