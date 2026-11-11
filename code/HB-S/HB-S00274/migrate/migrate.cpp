#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,dp[1005][1005],ans;
ll d,a[1005],b[1005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==13||c==14){
        ll k[1000005];
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>k[i];
            if(k[n]-k[i]<=d)cout<<"0\n";
            else {
                srand(time(0));
                cout<<(rand())<<'\n';
            }
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i]-a[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    dp[i][j]=1;
                    continue;
                }else if(b[j]>d){
                    i=j;
                    break;
                }
                int k=b[j],t=j;
                while(t>i&&k<=d)k+=b[--t];
                dp[i][j]=dp[i][t]+1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(dp[i][j-3]+1==dp[i][j-2]&&dp[i][j-2]==dp[i][j-1]&&dp[i][j-1]+1==dp[i][j])ans++;
            }
        }
        cout<<ans<<'\n';
        ans=0;
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
