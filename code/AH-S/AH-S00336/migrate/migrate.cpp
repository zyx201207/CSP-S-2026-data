#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t,n,dp[200010];ll d,a[2000010];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    d=floor(d*1.00/(a[2]-a[1]));
    if(d<=1)cout<<'0'<<'\n';
    else cout<<max(0ll,n-(d+(d-1)))<<'\n';
}
void solvea(){
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cout<<i<<":\n";
        for(int j=1;j<=n;j++)dp[j]=0;
        dp[i]=1;
        for(int j=i+1;j<=n;j++){
            for(int k=j-1;k>=i;k--){
                if(a[j]-a[k]>d)break;
                dp[j]+=dp[k];
            }
          //  cout<<"j="<<j<<' '<<dp[j]<<' ';
            if(dp[j]==2)++ans;
            if(dp[j]>2)break;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        if(c==11||c==12)solve();
        else solvea();
    }
}
