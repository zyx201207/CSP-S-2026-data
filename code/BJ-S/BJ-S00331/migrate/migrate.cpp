#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T;
ll n,d,a[N],dp[N],ds[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){

        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        //C
        ll ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            ds[i]=0;
            for(int j=i+1;j<=n;j++){
                ll mn=N;
                dp[j]=0;
                for(int k=j-1;a[j]-a[k]<=d&&k>=i;k--){
                    mn=min(ds[k],mn);
                }
                ds[j]=mn+1;
                for(int k=j-1;a[j]-a[k]<=d&&k>=i;k--){
                    if(ds[k]==mn){
                        dp[j]+=dp[k];
                    }
                }
                if(dp[j]==2) ans++;
                //cout<<dp[j]<<' '<<ds[j]<<endl;
            }
            //cout<<endl;
        }
        cout<<ans<<'\n';

    }
    // \|/
    return 0;
}
