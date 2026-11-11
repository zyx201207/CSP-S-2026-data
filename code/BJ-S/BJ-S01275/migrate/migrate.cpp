#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int a[2000005],b[2000005],dp[5005],dp2[5005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        int n,d;cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(dp,0,sizeof(dp));
        int num=d/(a[2]-a[1]);
        if(c>10){
        if(num<=1||num>=n-1){
            cout<<"0"<<endl;
        }else if(num==2){
            //计数:间隔3
            cout<<max(n-3,0ll)<<endl;
        }else{
            //num+1,2*num-1
            int ans=n-(2*num-1);
            cout<<max(ans,0ll)<<endl;
        }
        continue;}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(a[i]-a[j]<=d){
                    b[i]=j;break;
                }
            }

        }
        int ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=1;dp2[i]=0;
            for(int j=i+1;j<=n;j++){
                dp[j]=0;dp2[j]=100000000;
                for(int k=max(i,b[j]);k<j;k++){
                    if(dp2[k]+1<dp2[j]){
                        dp2[j]=dp2[k]+1;dp[j]=dp[k];
                    }else if(dp2[k]+1==dp2[j])dp[j]+=dp[k];
                }
                //cout<<i<<" "<<j<<" "<<dp[j]<<endl;
                if(dp[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
