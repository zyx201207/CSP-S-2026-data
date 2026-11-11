#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int n,m;
ll a[maxn],ned[maxn],res;
bool check(ll x,ll r){
    ll now=ned[r]-ned[x-1];
    ll neadd=a[r]*(r-x+1)-now;
    if(neadd<=m) return true;
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) ned[i]=ned[i-1]+a[i];
    ll tmp=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=i,ans=r;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid,i)){
                r=mid-1;
                ans=mid;
            }else l=mid+1;
        }
        res=max(res,i-ans+1);
    }
    cout<<res<<"\n";
    return 0;
}