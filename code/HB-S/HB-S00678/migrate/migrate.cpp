#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define db double
using namespace std;
const ll mx=2e6+5;
ll n,d,a[mx],nxt[mx],pr[mx];
pii dp[mx];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,T;cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<=3){cout<<"0\n";continue;}
        if(c==11||c==12){
            ll ans=0,gc=a[2]-a[1];
            d/=gc;
            if(d<=1){cout<<"0\n";continue;}
            cout<<max(0ll,n-2*d+1)<<"\n";
            continue;
        }
        if(c<=10){
            ll ans=0;
            for(int i=1;i<=n;i++){
                ll now=i;
                dp[i].first=0,dp[i].second=1;
                for(int j=i+1;j<=n;j++){
                    while(a[j]-a[now]>d)now++;
                    if(now==j||dp[now].second>2)break;
                    dp[j].first=dp[now].first+1;
                    dp[j].second=0;
                    for(int k=now;k<j;k++){
                        if(dp[k].first!=dp[now].first||dp[j].second>2)break;
                        dp[j].second+=dp[k].second;
                    }if(dp[j].second==2)ans++;
                }
            }cout<<ans<<"\n";
            continue;
        }if(c<=18){
            for(int i=1;i<=n;i++){
                pr[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
                nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            }ll ans=0;
            for(int i=1;i<=n;i++){
                ll k=nxt[i];
                if(a[n]-a[i]<=d)break;
                if(k==i+1)continue;
                ll g=k-1;
                ans+=nxt[k]-nxt[g];
            }cout<<ans<<"\n";
        }
    }
    return 0;
}