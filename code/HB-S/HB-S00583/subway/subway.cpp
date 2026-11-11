#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5;
int dp[N][N],ans[N][N],w[N],a[N][N],t[N][N];
int c,n,m,d,q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;cin>>x;a[i][0]=t[i][0]=x;
        for(int j=1;j<=x;j++){
            int y;
            cin>>a[i][j]>>y;
            t[a[i][j]][i]=y;
        }
            
    }
    memset(ans,0x3f,sizeof(ans));
    for(int k=1;k<=m;k++){
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++){
            if(a[i][1]!=k) continue;
            dp[a[i][1]][i]=t[a[i][1]][i];
            for(int j=2;j<=a[i][0];j++){
                dp[a[i][j]][i]=dp[a[i][j-1]][i];
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i][1]==k) continue;
            for(int j=1;j<=a[i][0];j++){
                dp[a[i][j]][i]=min(dp[a[i][j]][i],dp[a[i][j-1]][i]);
                for(int l=1;l<=n;l++){
                    if(l==i) continue;
                    dp[a[i][j]][i]=min(dp[a[i][j]][i],dp[a[i][j]][l]+t[a[i][j]][l]+t[a[i][j]][i]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i][0];j++) 
                ans[k][a[i][j]]=min(ans[k][a[i][j]],dp[a[i][j]][i]+t[a[i][j]][i]);
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<ans[l][r]+w[l]+w[r]<<endl;
    }
    return 0;
}