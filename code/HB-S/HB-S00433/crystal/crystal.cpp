#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],b[500005],cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool bq=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) bq=0;
    }sort(a+1,a+1+n);
    if(bq==1){
        ll ans=0,v=0;
        for(ll i=1;i<=n;i++){
            if(ans<=m) v=max(v,i-1);
            ans+=i;
        }
        cout<<min(n,v+1);
        return 0;
    }
    for(ll i=n-1;i>=1;i--){
        b[i]=b[i+1]+a[i+1]-a[i];
        cnt+=b[i];
    }
    ll l=1,r=n;
    while(cnt>m){
        ll q=b[l];
        ll w=b[r-1]*(r-l);
        if(q>w){
            cnt-=q;
            l++; -
        }else{
            cnt-=w;
            for(ll i=1;i<=n;i++){
                b[i]-=b[r-1];
            }
            r--;
        }
    }
    cout<<r-l+1;
    return 0;
}
