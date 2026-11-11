#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e3+5;
LL c,t,n,d,a[N],pre[N],dp[N][N],cnt[N][N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    for(LL o=1;o<=t;o++){
        cin>>n>>d;ans=0;
        for(LL i=1;i<=n;i++)cin>>a[i];
        LL l=1;
        for(LL i=1;i<=n;i++){
            while(a[i]-a[l]>d&&l<i)l++;
            pre[i]=l;
        }
        for(LL i=1;i<=n;i++)
            for(LL j=1;j<=n;j++){
                dp[i][j]=2e9;
                cnt[i][j]=0;
                if(i==j){
                    dp[i][j]=0;
                    cnt[i][j]=1;
                }
            }
        for(LL i=2;i<=n;i++){
            for(LL k=1;k<i;k++){
                for(LL j=max(pre[i],k);j<i;j++){
                    if(dp[j][k]+1>dp[i][k])break;
                    cnt[i][k]+=cnt[j][k];
                    dp[i][k]=dp[j][k]+1;
                }
            }
            for(LL j=1;j<i;j++){
                if(dp[i][j]<2e9&&cnt[i][j]==2){
                    ans++;
                }
            }
        }
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n;j++)cout<<dp[i][j]<<" ";
//            cout<<'\n';
//        }
        cout<<ans<<'\n';
    }
    return 0;
}
