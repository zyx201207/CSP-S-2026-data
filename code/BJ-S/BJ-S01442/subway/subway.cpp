#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510];
vector <pair <int, int> > att[510];
//vector <int> t[510];
vector <int> ia[500010];
vector <int> it[500010];
long long f[510][510];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in", "r",stdin);
    freopen("subway.out", "w",stdout);
    cin >> c>>n>>m>>d>>q;
    //cout << c << " " << n << " " << m  << ' ' << d << " " << q << '\n'; return 0;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            int aa,tt; cin >>aa>>tt;
            att[i].push_back({aa,tt});
            //t[i].push_back(tt);
            ia[aa].push_back(i);
            it[aa].push_back(tt);
        }
        sort(att[i].begin(), att[i].end());
        for(int j = 1; j <= n; j++){
            if(j != i) f[i][j] = 1e18;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            int lp = 0; int rp = 0;
            while(lp < k[i] && rp < k[j]){

                if(att[i][lp].first == att[j][rp].first){
                    f[i][j] = min(f[i][j], 0ll + att[i][lp].second +
                                  att[j][rp].second); lp++; rp ++; continue;
                }
                if(att[i][lp].first < att[j][rp].first){
                    pair <int, int> cr = {att[j][rp].first,0};
                    int nx = lower_bound(att[i].begin() + lp,att[i].end(),cr) - att[i].begin();
                    if(nx < k[i]){
                        lp = nx; continue;
                    }
                    else break;
                }
                if(att[i][lp].first > att[j][rp].first){
                    pair <int, int> cr = {att[i][lp].first,0};
                    int nx = lower_bound(att[j].begin() + rp,att[j].end(),cr) - att[j].begin();
                    if(nx < k[j]){
                        rp = nx; continue;
                    }
                    else break;
                }
            }
        }

    }
    //cout << 114 << '\n'; return 0;
/*    for(int i = 1; i <= m; i++){
        for(int l = 0; l < ia[i].size() - 1; l ++){
            for(int r = l + 1; r < ia[i].size(); r++){
                int cr = it[i][l] + it[i][r];
                f[ia[i][l]][ia[i][r]] = min(f[ia[i][l]][ia[i][r]], cr);
            }
        }
    }
    */
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            long long cr = min(f[i][j], f[j][i]);
            f[i][j] = cr; f[j][i] = cr;
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }//return 0;
    while(q --){
        int x,y; cin >> x >> y;
        long long pr = w[x] + w[y]; long long ans = 1e18;
        for(int i = 0; i < ia[x].size(); i++){
            for(int j = 0; j < ia[y].size(); j++){
                int p = ia[x][i]; int q = ia[y][j];
                ans = min(ans, 0ll + f[p][q] + it[x][i] + it[y][j]);
            }
        }
        cout << ans + pr << '\n';
    }
    return 0;
}
