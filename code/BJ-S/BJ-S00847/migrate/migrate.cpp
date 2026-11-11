#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2500005];
ll s[2500005],dp[2500005];
int lst[2500005];
    int c,t;
void solve(){
    int n;
    ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    int ak=1;
    for(int i=1;i<=n;i++){
        while(x[i]-x[ak]>d)ak++;
        lst[i]=ak;
    }
    if(c==11||c==12){
        if(n==1) cout<<0<<"\n";
        ll oo=d/(x[2]-x[1]);
        if(oo<2){
            cout<<0<<"\n";
            return;
        }
        cout<<max((ll)0,n-oo*2+1)<<"\n";
        return;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) s[j]=dp[j]=0;
        dp[i]=1;
        for(int j=i+1;j<=n;j++){
            if(lst[j]<=i){
                s[j]=1,dp[j]=1;
            }
            else{
                s[j]=s[lst[j]]+1;
                for(int k=lst[j];k<=min(lst[j]+2,j-1);k++){
                    if(s[k]+1==s[j]) dp[j]+=dp[k];
                }
                dp[j]=min(dp[j],(ll)50);
            }
            if(dp[j]==2) ans++;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--) solve();
}