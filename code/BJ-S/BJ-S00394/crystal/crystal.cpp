#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FASTIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const ll MAXN=5*1e5+10;
ll a[MAXN],pre[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    FASTIO;
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    sort(a+1,a+n+1);
    ll j=1;
    for(ll i=1;i<=n;++i){
        while(j<=n&&a[j]*(j-i+1)-(pre[j]-pre[i-1])<=m){
            ++j;
        }
        --j;
        if(j-i+1>ans){
            ans=max(ans,j-i+1);
        }
    }
    cout<<ans;
    return 0;
}
