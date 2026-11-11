#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
const int N=2e6+12;
void solve(){
    ll n,d,x[N];
    cin>>n>>d;
    f(i,1,n){
        cin>>x[i];
    }
    pair<ll,ll> p[N];
    ll dp[N];
    f(i,1,n) dp[i]=1e18+67;
    dp[1]=1;
    dp[2]=1;
    f(i,3,n){
        f(j,1,d){
            if(dp[i]>dp[i-j]+1){
                p[i].first=dp[i-j]+1;
                p[i].second=1;
            }
            else if(dp[i]==dp[i-j]+1){
                p[i].second++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t=1,c;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
