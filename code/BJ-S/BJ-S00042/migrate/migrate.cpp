#include<bits/stdc++.h>
using namespace std;
int c;
typedef long long ll;
const int MAXN=2e6+5;
ll x[MAXN],dp[MAXN],f[MAXN];
void solve(){
    int n;
    ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    if(n<=5000){
        ll ans=0;
        for(int l=1;l<=n;l++){
            memset(dp,0,sizeof(dp));
            memset(f,0,sizeof(f));
            f[l]=1;
            for(int i=l+1,j=l;i<=n;i++){
                while(j<i&&x[i]-x[j]>d)j++;
                ll minn=n+1;
                for(int k=j;k<i;k++){
                    minn=min(minn,dp[k]+1);
                }
                dp[i]=minn;
                for(int k=j;k<i;k++){
                    if(dp[k]+1==dp[i])f[i]+=f[k];
                }
                if(f[i]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}
