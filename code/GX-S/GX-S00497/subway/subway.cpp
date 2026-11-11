#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],t[501][5005],k[501],a[501][5005];
long long dp[5001][5001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)dp[i][j]=dp[j][i]=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int h=j+1;h<=k[i];h++){
                dp[a[i][j]][a[i][h]]=dp[a[i][h]][a[i][j]]=t[i][j]+t[i][h];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i!=j)for(int h=1;h<=m;h++){
                if(i!=h&&j!=h)dp[j][h]=dp[h][j]=min(dp[j][h],dp[i][j]+dp[i][h]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y]+w[x]+w[y]<<endl;;
    }
    return 0;
}
