#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll x = 0,h = 1;
    char ch = getchar();
    while(!(ch=='-'||('0'<=ch&&ch<='9'))) ch = getchar();
    if(ch=='-') h = -1;
    else x = ch-'0';
    ch = getchar();
    while('0'<=ch&&ch<='9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*h;
}
namespace G4M1{
    //if fly shorter >=2 is ok
    //then fly shorter 1,0 is both ok this is wrong
    //so is about fly shorter 1 at some place
    //is the situation is fly:max max max ... .. nomax
    //nomax will be short 1?
    const ll N = 2000010;
    const ll M = 310;
    const ll INF = 1e16;
    ll n,D;
    ll a[N];
    pair<ll,ll> dp[M][M];
    void main(ll cid){
        n = read(),D = read();
        for(ll i = 1; i <= n; i++) a[i] = read();
        if(cid<=10){
            for(ll i = 1; i <= n; i++){
                dp[i][i] = {0,1};
                for(ll j = i-1; j >= 1; j--){
                    dp[i][j] = {INF,0};
                    if(a[i]-a[j]<=D) dp[i][j] = {1,1};
                    else {
                        for(ll k = j+1; k < i; k++){
                            if(!(a[i]-a[k]<=D)) continue;
                            if(dp[k][j].first+dp[i][k].first<dp[i][j].first) dp[i][j] = {dp[k][j].first+dp[i][k].first,dp[k][j].second*dp[i][k].second};
                            else if(dp[k][j].first+dp[i][k].first==dp[i][j].first) dp[i][j].second+=dp[k][j].second*dp[i][k].second;
                        }
                    }
                    //printf("dp[%lld][%lld] = {%lld,%lld}\n",i,j,dp[i][j].first,dp[i][j].second);
                }
            }
            ll ans = 0;
            for(ll i = 1; i <= n; i++) for(ll j = i; j <= n; j++) if(dp[j][i].second==2) ans++;
            printf("%lld\n",ans);
        } else if(cid==11||cid==12){
            ll x = 1;
            if(a[n]-a[1]<=D||a[2]-a[1]>=D) puts("0");
            else {
                while(a[x]-a[1]<=D) x++;
                x--;
                ll p = 2*x-2;
                printf("%lld\n",(n-p+1));
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll cid = read(),T = read();
    while(T--) G4M1::main(cid);
    return 0;
}
