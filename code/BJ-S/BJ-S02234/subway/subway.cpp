#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005],dp[5005][5005];
ll c, n, m, d, k, q, ai[500005], ti[500005], xi, yi;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                if(i == j) dp[i][j] = 0;
                else dp[i][j] = 100000005;
            }
        }
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> ai[j] >> ti[j];
        }   
        for(int j = 1; j <= k; j++){
            for(int jj = j + 1; jj <= k; jj++){
                dp[ai[j]][ai[jj]] = min(dp[ai[j]][ai[jj]],ti[j]+ti[jj]);
                dp[ai[jj]][ai[j]] = min(dp[ai[jj]][ai[j]],ti[j]+ti[jj]);
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = i+1; j <= m; j++){
            for(int kk = i+1; kk < j; kk++){
                dp[i][j] = min(dp[i][j],dp[i][kk]+dp[kk][j]);
            }
        }
    }
    while(q--){
        cin >> xi >> yi;
        cout << dp[xi][yi] + w[xi] + w[yi] << '\n';
    }
    return 0;
}