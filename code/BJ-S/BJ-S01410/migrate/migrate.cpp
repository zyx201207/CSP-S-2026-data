#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[2000001];
ll dp[5001][5001],cnt[5001][5001],mst[5001];
ll f[2000001][3],ans,s[2000001][3];
void solve(ll l,ll r){
    for(int i=l;i<=r;i++){
        for(int j=l+1;j<=r;j++) dp[i][j]=2e18,cnt[i][j]=0;
        dp[i][i]=0,cnt[i][i]=0;
        for(int j=i+1;j<=r;j++){
            if(a[j]-a[i]>d) break;
            dp[i][j]=1,cnt[i][j]=1,mst[i]=j;
        }
    }
    for(int lens=1;lens<=r-l+1;lens++){
        for(int i=l;i<=r-lens+1;i++){
            for(int j=i+1;j<=mst[i];j++){
                if(dp[i][i+lens-1]>dp[i][j]+dp[j][i+lens-1]){
                    dp[i][i+lens-1]=dp[i][j]+dp[j][i+lens-1];
                    cnt[i][i+lens-1]=cnt[i][j]*cnt[j][i+lens-1];
                }else if(dp[i][i+lens-1]==dp[i][j]+dp[j][i+lens-1]){
                    cnt[i][i+lens-1]+=cnt[i][j]*cnt[j][i+lens-1];
                }
            }
        }
    }
    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){
            if(cnt[i][j]==2) ans++;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >>c >>t;
    while(t--){
        cin >>n >>d;
        ll pre=1;
        ans=0;
        for(int i=1;i<=n;i++){
            cin >>a[i];
            if(a[i]-a[i-1]>d) solve(pre,i-1),pre=i;
        }
        solve(pre,n);
        cout <<ans <<'\n';
    }
    return 0;
}
