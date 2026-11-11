#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500009];
ll s[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    ll l=0,r=n,mx=0;
    while(l<=r){
        ll mid=(l+r)/2,ttt=0;
        for(ll i=mid;i<=n;i++){
            if(a[i]*mid-(s[i]-s[i-mid-1])<=k){
                ttt=1;
            }
        }
        if(ttt==0){
            r=mid-1;
        }else{
            mx=mid;
            l=mid+1;
        }
    }
    cout<<mx;
    return 0;
}
