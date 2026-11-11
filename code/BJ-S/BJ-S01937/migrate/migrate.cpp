#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int c,t,n,p[N],cnt,tot,dp[N][N],f[N][N];
ll x[N],d,ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;cnt=tot=ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            p[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            if(x[n]<=x[i]+d) p[i]=n;
            for(int j=1;j<=n;j++) dp[i][j]=0;
        }
        for(int i=1;i<=n;i++){
            dp[i][i]=1;f[i][i]=0;int j=i,cnt=0;
            while(j<=n){
                for(int k=j+1;k<=p[j];k++){
                    f[i][k]=cnt+1;
                }
                cnt++;
                if(j==p[j]) break;
                j=p[j];
            }
            for(int j=i;j<=n;j++){
                for(int c=0;c<=2;c++){
                    if(p[j]-c>i&&f[i][p[j]-c]==f[i][j]+1){
                        dp[i][p[j]-c]+=dp[i][j];
                        if(dp[i][p[j]-c]>3) dp[i][p[j]-c]=3;
                    }
                }
                if(dp[i][j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
