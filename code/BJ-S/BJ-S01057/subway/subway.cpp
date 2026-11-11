#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Min(x,y) x=min(x,y)
ll a[666666];
ll dp[666][666];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(dp,63,sizeof(dp));
    for (int i = 1;i<=m;i++){
        cin>>a[i];
        dp[i][i] = 0;
    }
    for (int i = 1;i<=n;i++){
        int x;
        cin>>x;
        vector<pair<ll,ll> > line;
        for (int j = 1;j<=x;j++){
            int sss,ttt;
            cin>>sss>>ttt;
            line.push_back({sss,ttt});
        }
        for (int j = 0;j<x;j++){
            for (int k = j+1;k<x;k++){
                Min(dp[line[j].first][line[k].first],line[j].second+line[k].second);
                Min(dp[line[k].first][line[j].first],line[j].second+line[k].second);
            }
        }
    }
    for (int i = 1;i<=m;i++){
        for (int j = 1;j<=m;j++){
            if (dp[i][j]>1e18) continue;
            for (int k = 1;k<=m;k++){
                Min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y]+a[x]+a[y]<<"\n";
    }
    return 0;
}
