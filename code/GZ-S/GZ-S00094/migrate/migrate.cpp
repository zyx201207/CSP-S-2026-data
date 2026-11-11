//GZ-S00094 中央民族大学附属中学贵阳学校 伍兴睿麟
#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int mod=1e9+7;
ll qp(ll x,ll y){ll res=0;while(y){if(y&1) res=res*x%mod;x=x*x%mod;y/=2;}return res%mod;}
int n,c,t,l[505];
ll a[506],dp[305][305][305],d,pr[305][305][305];
void so(){
    cin>>n>>d;
    memset(dp,0,sizeof dp);
    memset(pr,0,sizeof pr);
  //  dp[1][1][0]=1;
    for(int i=1;i<=n;i++) cin>>a[i],l[i]=lower_bound(a+1,a+1+i,a[i]-d)-a,dp[i][i][0]=1;
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) pr[i][j][0]=1;
    for(int j=2;j<=n;j++) {
        for(int i=j-1;i>=1;i--){
            for(int k=300;k>=1;k--) {
                dp[i][j][k]=min(ll(3),pr[i][j-1][k-1]-pr[i][l[j]-1][k-1]);
                pr[i][j][k]=dp[i][j][k]+pr[i][j-1][k];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<n;i++) {
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=300;k++) {
                if(dp[i][j][k] ) {
                    if(dp[i][j][k]==2){
                            ans++;
                    }
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        so();
    }
    return 0;
}
