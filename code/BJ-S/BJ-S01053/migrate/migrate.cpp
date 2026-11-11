#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[200010],ans,dp[5010][5010],dp2[5010][5010],s[5010][5010],p[5010][5010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dp[i][j]=dp2[i][j]=s[i][j]=p[i][j]=0;
        }
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            dp[i][i]=0,dp2[i][i]=1,s[i][i]=1,p[i][0]=i;
            for(int j=i+1;j<=n;j++){
                int l=i-1,r=j;
                while(l+1<r){
                    int mid=(l+r)/2;
                    if(x[j]-x[mid]>d) l=mid;
                    else r=mid;
                }
                dp[i][j]=dp[i][r]+1;
                dp2[i][j]+=s[i][p[i][dp[i][r]]]-s[i][r-1];
                s[i][j]=s[i][j-1]+dp2[i][j];
                p[i][dp[i][j]]=j;
                if(dp2[i][j]==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}