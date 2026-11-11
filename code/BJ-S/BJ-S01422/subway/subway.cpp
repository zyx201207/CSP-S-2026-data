#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[505][505];
ll a[505];
ll x[5005],t[6006];
ll c,n,m,d,q;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=m;i++){
        int k;cin>>k;
        dp[i][i]=0;
        for(int j=1;j<=k;j++) cin>>x[j]>>t[j];
        for(int j=1;j<=k;j++){
            for(int o=j+1;o<=k;o++){
                dp[x[o]][x[j]]=dp[x[j]][x[o]]=t[j]+t[o];
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i==j) continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<a[l]+dp[l][r]+a[r]<<"\n";
    }
    return 0;
}
