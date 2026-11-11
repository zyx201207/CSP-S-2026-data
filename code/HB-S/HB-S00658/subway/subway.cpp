#include <bits/stdc++.h>
using namespace std;

#define int long long

int c,n,m,d,q;

const int M = 5e5 + 10;
const int N = 510;

int w[M],k[N];
vector <int> a[N],t[N];
vector <pair<int,int> > hav[M];
int mp[N][N];

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen ("subway.in","r",stdin);
    freopen ("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++){
        cin >> w[i];
    }
    for (int i=1;i<=n;i++){
        cin >> k[i];
        for (int j=1;j<=k[i];j++){
            int v = 0, ww = 0;
            cin >> v >> ww;
            a[i].push_back(v); t[i].push_back(ww);
            hav[v].push_back(make_pair(i,ww));
        }
    }

    memset (mp,0x3f,sizeof(mp));

    for (int i=1;i<=n;i++){
        mp[i][i] = 0;
    }

    for (int i=1;i<=m;i++){
        for (int j=0;j<hav[i].size();j++){
            for (int l=0;l<hav[i].size();l++){
                if (j == l) continue;
                if (mp[hav[i][j].first][hav[i][l].first] > hav[i][j].second + hav[i][l].second){
                    mp[hav[i][j].first][hav[i][l].first] = hav[i][j].second + hav[i][l].second;
                }
            }
        }
    }

    for (int l=1;l<n;l++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i == j || j == l || i == l) continue;
                if (mp[i][j] > mp[i][l] + mp[l][j]){
                    mp[i][j] = mp[i][l] + mp[l][j];
                }
            }
        }
    }

    while (q--){
        int x,y;
        cin >> x >> y;
        int res = 1e18;
        for (int i=0;i<hav[x].size();i++){
            for (int j=0;j<hav[y].size();j++){
                if (mp[hav[x][i].first][hav[y][j].first] + hav[x][i].second + hav[y][j].second < res){
                    res = mp[hav[x][i].first][hav[y][j].first] + hav[x][i].second + hav[y][j].second;
                }
            }
        }
        cout << res + w[x] + w[y] << '\n';
    }

    return 0;
}
