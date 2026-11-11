#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    for(ll i=1;i<=t;i++){
        ll n,d;
        cin>>n>>d;
        ll a[n+1];
        for(ll i=1;i<=n;i++)cin>>a[i];
        ll dp[n+1];
        memset(dp,0x3f3f3f,sizeof dp);
        dp[0]=1;
        ll cnt=0;
        for(ll i=1;i<=n;i++){
            ll j=i;
            while(a[i]-a[j]<=d&&j>0){
                if(dp[i]==dp[i]+a[i]-a[j])cnt++;
                dp[i]=min(dp[i],dp[i]+a[i]-a[j]);
                j--;
            }
        }
        cout<<cnt<<endl;
    }



    return 0;
}
