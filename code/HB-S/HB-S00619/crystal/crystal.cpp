#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAXN=5*(ll)1e5+5;
ll a[MAXN];
ll n,m;
ll p[MAXN];
ll getSum(ll l,ll r){
    return p[r]-p[l-1];
}
bool cheak(ll ans){
    ll minNeed=LONG_LONG_MAX;
    // int n_;
    for(ll i=ans;i<=n;i++){
        ll need=a[i]*ans-getSum(i-ans+1,i);
        minNeed=min(minNeed,need);
        // if(minNeed==need){
        //     n_=i;
        // }
    }
    // cout<<"ans="<<ans<<" need="<<minNeed<<' '<<n_<<'\n';
    return minNeed<=m;
}
ll ef(){
    ll l=1,r=n,mid;
    while(l<r){
        mid=(l+r+1)/2;
        if(cheak(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    p[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        // p[i]=p[i-1]+a[i];
    }
    // cout<<p[250095]<<' '<<getSum(250095-250001+1,250001)<<' '<<a[250095]<<endl;
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<endl;
    cout<<ef()<<endl;
    return 0;
}

/*
5 5
1 2 4 8 9

3
*/

/*
5 8
-3 -1 2 2 7

4
*/