#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 2e5+5;
ll n,m;
ll a[M];
ll ans1(ll i,ll k,ll s){
    if(i > n){
        if(k == m) return s;
        return 0;
    }
    ll ss=0;
    ss=ans1(i+1,k,s);
    if(k<m){
        if(k == 0) ss = max(ss,ans1(i+1,k+1,a[i]));
        else ss=max(ss,ans1(i+1,k+1,s&a[i]));
    }
    return ss;
}
ll ans2(){
    ll s=0;
    for(ll i=1;i<=n;i++){
        s = max(a[i],s);
    }
    return s;
}
ll ans3(){
    ll s=a[1];
    for(ll i=2;i<=n;i++){
        s = s&a[i];
    }
    return s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans = 0;
    if(n<=20) ans=ans1(1,0,0);
    if(m==1) ans = ans2();
    if(m==n) ans = ans3();
    cout<<ans;
    return 0;
}

