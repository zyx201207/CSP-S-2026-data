#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ffor(i,a,b) for(ll i=(a);i<(b);++i)
ll a[500500];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    bool sp=1;
    ll delta=0;
    cin>>n>>m;
    ffor(i,0,n){
        cin>>a[i];
        if(!delta&&i!=0)delta=a[i]-a[i-1];
        if(a[i]-a[i-1]!=delta)sp=0;
    }
    sort(a,a+n,[](ll a,ll b){
        return a>b;
    });
    if(sp){
        ll sm=delta;
        ffor(i,1,n){
            if(sm>m)break;
            sm+=sm*2;
        }
        cout<<sm<<'\n';
        return 0;
    }
    ll ans=0;
    ffor(i,0,n){
        ll cz=m,res=0;
        ffor(j,i,n){
            ll d=a[i]-a[j];
            if(d<=cz)cz-=d,res++;
        }
        ans=max(ans,res);
    }
    cout<<ans<<'\n';
    return 0;
}