#include<bits/stdc++.h>
using namespace std;
const long long inf=2e18+5;
struct node{
    long long val,sum;
}dp[5005][5005];
long long a[5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dp[i][j].val=inf;
                dp[i][j].sum=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    dp[i][j]={1,1};
                }
                else{
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int l=1;l<i;l++){
                for(int r=i+1;r<=n;r++){
                    long long nw=dp[l][i].val+dp[i][r].val;
                    if(nw<dp[l][r].val){
                        dp[l][r].val=nw;
                        dp[l][r].sum=1;
                    }
                    else if(nw==dp[l][r].val&&dp[l][r].sum!=-1){
                        dp[l][r].sum++;
                        if(dp[l][r].sum>2){
                            dp[l][r].sum=-1;
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j].sum==2&&dp[i][j].val<inf){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
