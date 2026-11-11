#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll x[N],c,t,n,d,dp[N][2],flag[2];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(x,0,sizeof(x));
        ll ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int k=1;k<n;k++){
            memset(dp,0,sizeof(dp));
            //cout<<"k:"<<k<<endl;
            dp[k][0]=1;
            int now=1;
            for(int i=k+1;i<=n;i++){
                for(int j=i-1;j>=k;j--){
                //if(i==n&&k==1) cout<<"k==1 x[i]==10: j:"<<j<<" xi:"<<x[i]<<" xj:"<<x[j]<<" d:"<<d<<" d j 1-now:"<<endl;
                    if(x[i]-x[j]>d){
                        break;
                    }
                    dp[i][now]+=dp[j][1-now];
                }
                if(dp[i][now]==0){
                    now=1-now;
                    for(int j=i-1;j>=k;j--){
                        if(x[i]-x[j]>d){
                            break;
                        }
                        dp[i][now]+=dp[j][1-now];
                    }

                }
                if(dp[i][now]==2){
                    ans++;
                }
            }/*
            if(k==1){
                for(int i=1;i<=n;i++){
                    for(int j=0;j<=1;j++){
                        cout<<dp[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }*/
        }
        cout<<ans<<endl;
    }
    return 0;
}
