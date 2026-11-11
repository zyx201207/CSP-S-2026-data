#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+5;
LL x[N],dp[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    LL c,T,n,d;
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(LL i=1;i<=n;i++){
            cin>>x[i];
        }
        LL ans=0,pre;
        for(LL i=1;i<=n;i++){
            dp[i]=0;
            pre=i;
            for(LL j=i+1;j<=n;j++){
                if(x[j]-x[pre]<=d){
                    dp[j]=dp[pre]+1;
                }
                else{
                   while(x[j]-x[pre]>d&&pre<j){
                      pre++;
                   }
                   dp[j]=dp[pre]+1;
                }
                if(x[j]-x[j-1]>d) break;
            }
            LL cnt=1,cum=1,ans=0;
            for(LL j=i+2;j<=n;j++){
                if(dp[j-1]==dp[j]){
                    cnt++;
                }
                else{
                    cum*=cnt;
                    cnt=1;
                }
                if(cum*cnt==2&&j-i>=3) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

