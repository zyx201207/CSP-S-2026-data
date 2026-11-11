#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+70;
ll a[N];int n,m;
ll pre[N];
bool check(ll n){
    return a[n]*n-pre[n]<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll l=1,r=n;
    ll ans=0;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<ans<<" ";
    return 0;
}
