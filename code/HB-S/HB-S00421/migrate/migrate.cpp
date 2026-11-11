#include<bits/stdc++.h>
#define it long long
using namespace std;
it c,t,n,d,a[2000005],dp[5005][5005],dis[5005][5005],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        ans=0;
        memset(dis,0x3f,sizeof(dis));
        cin>>n>>d;
        for(it i=1;i<=n;i++) cin>>a[i],dis[i][i]=0,dp[i][i]=1;
        for(it len=2;len<=n;len++){
            for(it l=1;l+len<=n+1;l++){
                it r=l+len-1;
                if(a[r]-a[l]<=d) dis[l][r]=dp[l][r]=1;
                else{
                    for(int mid=l+1;mid<r;mid++){
                        if(dis[l][mid]+dis[mid][r]<dis[l][r]){
                            dis[l][r]=dis[l][mid]+dis[mid][r];
                            dp[l][r]=dp[l][mid]*dp[mid][r];
                        }else if(dis[l][mid]+dis[mid][r]==dis[l][r]) dp[l][r]+=dp[l][mid]*dp[mid][r];
                    }
                    if(dp[l][r]==2) ans++;
                    else if(dp[l][r]>2) dp[l][r]=0;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
