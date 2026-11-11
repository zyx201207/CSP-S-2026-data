#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll db=0;
void solve(ll n,ll m,vector<ll>&a){
    sort(a.begin()+1,a.end());
    vector<ll>s(n+1);
    for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    ll ans=0;
    for(ll i=1,j=1;i<=n&&j<=n;j++){
        ll c=a[j]*(j-i+1)-(s[j]-s[i-1]);
        while(c>m){
            c-=a[j]-a[i];
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,m;cin>>n>>m;
    vector<ll>a(n+1);
    for(ll i=1;i<=n;i++)cin>>a[i];
    solve(n,m,a);
    return 0;
}
