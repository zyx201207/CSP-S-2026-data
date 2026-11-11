#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int dp[505][505];
int w[500005];
vector<pair<int,int>> roo[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c>> n>> m>> d>> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = INT_MAX;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin >> a >> t;
            roo[a].push_back({i,t});
        }
        dp[i][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(auto a:roo[i]){
            for(auto b:roo[i]){
                dp[a.first][b.first] = min(dp[a.first][b.first],a.second+b.second);
                dp[b.first][a.first] = dp[a.first][b.first] ;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int a,b,ans = INT_MAX;
        cin >> a >> b;
        for(auto i:roo[a]){
            for(auto j:roo[b]){
                ans = min(i.second+j.second+w[a]+w[b]+dp[i.first][j.first],ans);
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdout);
    fclose(stdin);
}
