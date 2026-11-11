#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ms,a[500005],ans;
ll check(ll s,ll sm){
    ll r=0,nl=ms;
    for(int i=s-1;i>0;i--){
       if(nl>=(sm-a[i])){
        nl-=(sm-a[i]);
        r++;
       } else break;
    }
    r++;
    return r;
}
void rfda(){
    ll l=1,r=n;
    while(l<=r){
        ll m=(l+r)/2;
        ll b=check(m,a[m]);
        if(b>=ans){
            ans=b;
            l=m+1;
        }else r=m-1;
    }
    cout<<ans;
    return ;
}
int main(){
    freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    cin>>n>>ms;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(1+a,1+a+n);
    rfda();
    return 0;
}
