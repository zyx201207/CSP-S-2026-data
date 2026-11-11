#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll v[500010];
ll n,m;
ll ans=0;
ll c(ll x){
    ll a=0;
    ll nn=0;
    ll xx=0;
    for(ll i=0;i<n;i++){
        if(x<v[i]){
            a=i-1;
            break;
        }
    }
    for(ll i=a;i>=0;i--){
        nn+=x-v[i];
        if(nn>m)break;
        xx++;
    }  
    return xx;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ll x=m;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        v[i];
    }
    if(m>100000000){
        int xxx=v[1]-v[0];
        int xxxx=0;
        for(int i=1;i<=n;i++){
            xxxx+=xxx*i;
            if(xxxx>m){
                break;
            }
            ans++;
        }
        cout<<min(ans+1,n);
        return 0;
    }
    sort(v,v+n);
    for(ll i=v[0];i<=v[n-1];i++){
        ans=max(ans,c(i));
    }
    cout<<ans;
    //cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s";
    ll b;
    return 0;
}