#include <bits/stdc++.h>
using namespace std;

#define ll long long

int c, n, m, d, q;

ll w[500005];

ll dp[505][505];

vector <pair<int,ll>> dtlist[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    memset(dp,0x3f,sizeof dp);
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        dp[i][i] = 0;
        for(int j = 1;j <= k;j++){
            int a;
            ll t;
            cin >> a >> t;
            dtlist[a].push_back({i,t});
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < dtlist[i].size();j++){
            for(int k = j+1;k < dtlist[i].size();k++){
                dp[dtlist[i][k].first][dtlist[i][j].first] = dp[dtlist[i][j].first][dtlist[i][k].first] = dtlist[i][j].second+dtlist[i][k].second;
            }
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for(int j = 0;j < dtlist[x].size();j++){
            for(int k = 0;k < dtlist[y].size();k++){
                ans = min(ans,dp[dtlist[x][j].first][dtlist[y][k].first]+dtlist[x][j].second+dtlist[y][k].second);
            }
        }
        cout << ans+w[x]+w[y] << "\n";
    }
    return 0;
}