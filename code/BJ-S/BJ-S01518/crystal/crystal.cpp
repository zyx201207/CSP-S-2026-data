#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=5e5+5;
ll a[N];
ll pre[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll l=1,r=i,wei=i;
        while(l<=r){
            ll mid=(l+r)>>1;
            ll t=pre[i]-pre[mid-1];
            ll tot=(i-mid+1)*a[i];
            if(tot-t<=m){
                r=mid-1;
                wei=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,(i-wei)+1);
    }
    cout<<ans<<"\n";
    return 0;
}