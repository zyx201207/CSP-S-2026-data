#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005],b[2000005];
int dp[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if (1<=c && c<=10 || c==0){
        while(t--){
            int n,d;
            cin>>n>>d;
            for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
            int ans=0;
            for (int i=1;i<=n;i++){
                for (int j=i+1;j<=n;j++){
                    if (a[j]-a[j-1]>d) break;
                    if (a[j]-a[i]<=d){
                        dp[j]=1;
                        b[j]=1;
                    }
                    else{
                        b[j]=9e18;
                        for (int k=j-1;a[j]-a[k]<=d;k--){
                            b[j]=min(b[j],b[k]+1);
                        }
                        for (int k=j-1;a[j]-a[k]<=d;k--){
                            if (b[k]+1==b[j]) dp[j]+=dp[k];
                        }
                        if (dp[j]==2) ans++;
                    }
                }
                for (int j=i+1;j<=n;j++) dp[j]=0;
            }
            cout<<ans<<endl;
            for (int i=1;i<=n;i++) a[i]=0;
        }
    }
    return 0;
}
