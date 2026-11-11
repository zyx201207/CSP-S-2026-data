#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
long long c,n,m,d,q,w[M],k[N];
vector<long long>a[N],b[M];
vector<long long>t[N],p[M];
long long dp[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            long long x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            b[x].push_back(i);
            p[x].push_back(y);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<b[i].size();j++){
            for(int k=j+1;k<b[i].size();k++){
                dp[b[i][j]][b[i][k]]=dp[b[i][k]][b[i][j]]=min(dp[b[i][j]][b[i][k]],p[i][j]+p[i][k]);
                //<<b[i][j]<<" "<<b[i][k]<<" "<<dp[b[i][j]][b[i][k]]<<endl;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                dp[x][y]=min(dp[x][y],dp[x][k]+dp[y][k]);
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=1;i<=q;i++){
        long long x,y,ans=1e18;
        cin>>x>>y;
        for(int j=0;j<b[x].size();j++){
            for(int k=0;k<b[y].size();k++){
                ans=min(ans,w[x]+p[x][j]+dp[b[x][j]][b[y][k]]+p[y][k]+w[y]);
                //cout<<ans<<endl;
                //cout<<w[x]<<" "<<p[x][j]<<" "<<dp[x][y]<<" "<<p[y][k]<<" "<<w[y]<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
