#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,m;
int a[N],dp[N],dp2[N];
int ql[N];
int f[N][2];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],ql[i]=0;
    if(n<=300){
        int ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=0,dp2[i]=1;
            for(int j=i+1;j<=n;j++){
                dp[j]=1e18,dp2[j]=0;
                for(int k=i;k<j;k++){
                    if(a[j]-a[k]>m) continue;
                    if(dp[j]>dp[k]+1) dp[j]=dp[k]+1,dp2[j]=dp2[k];
                    else if(dp[j]==dp[k]+1) dp2[j]=min(3ll,dp2[j]+dp2[k]);
                }
                if(dp2[j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
        return;
    }
    for(int i=1,j=1;i<=n;i++){
        while(a[i]-a[j]>m) j++;
        ql[i]=j;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        f[i][0]=1,f[i][1]=0;
        if(ql[i]==i) continue;
        if(ql[i]==i-1){
            f[i][0]=1+f[ql[i]][0];
            f[i][1]=f[ql[i]][1];
            ans+=f[i][1];
            continue;
        }
        int posl=ql[ql[i]+1],posr=ql[i]-1;
        if(ql[i]+2<i) posr=min(posr,ql[ql[i]+2]-1);
        if(posl>posr){
            f[i][0]=i-ql[i]+(posl>ql[ql[i]]?f[ql[i]][0]:1);
            f[i][1]=0;
            continue;
        }
        if(posl==ql[ql[i]]){
            f[i][0]=i-ql[i]+1;
            f[i][1]=f[ql[i]][0]-(ql[i]-posr);
            ans+=f[i][1];
            continue;
        }
        f[i][0]=i-ql[i]+f[ql[i]][0]-(ql[i]-posl);
        f[i][1]=f[ql[i]][1]+(posr-posl+1);
        ans+=f[i][1];
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    cin>>_>>_;
    while(_--) solve();
    return 0;
}