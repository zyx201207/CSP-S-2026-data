#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long a[2000005],d,dp[2000005],maxx[2000505],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx[i]=1e18;
        }
        maxx[1]=0;
        if(n<=5000){
            for(int i=n;i>=1;i--){
                if(dp[i]==2)ans++;
                for(int j=i-1;j>=1;j--){
                    if(a[i]-a[j]>d)break;
                    if(maxx[j]>maxx[i]+1){
                        maxx[j]=maxx[i]+1;
                        dp[j]=1;
                    }else if(maxx[j]==maxx[i]+1){
                        dp[j]++;
                    }
                }
            }
        }
        cout<<ans<<endl;ans=0;
    }
    return 0;
}
