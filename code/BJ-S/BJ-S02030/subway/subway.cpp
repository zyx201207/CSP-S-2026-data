#include <bits/stdc++.h>
using namespace std;
int w[10005];
int f[10005][10005];
vector<pair<int, int> > a[505];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(f, 0x3f, sizeof(f));
    int c, n, m, d, q, x, y;
    cin >> c >> n >> m >> d >>q;
    for (int i=1; i<=m; ++i){cin >> w[i];f[i][i]=0;}
    for (int i=1; i<=n; ++i){
        int k;
        cin >> k;
        for (int j=1; j<=k; ++j){
            int ta, tt;
            cin >> ta >> tt;
            for (int k=0; k<a[i].size(); ++k){
                f[a[i][k].first][ta]=min(f[a[i][k].first][ta], a[i][k].second+tt);
                f[ta][a[i][k].first]=min(f[a[i][k].first][ta], a[i][k].second+tt);
            }
            a[i].push_back({ta, tt});
        }
    }
    for (int k=1; k<=m; ++k){
        for (int i=1; i<=m; ++i){
            for (int j=1; j<=m; ++j){
                f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
            }
        }
    }
    for (int i=1; i<=q; ++i){
        cin >> x >> y;
        cout << f[x][y]+w[x]+w[y] << '\n';
    }
    return 0;
}