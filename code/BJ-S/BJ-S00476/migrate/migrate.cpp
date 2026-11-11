#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const ll maxn=2e6+5;
ll c,t,n,d,a[maxn];
vector<ll> v,rv;
bool ok(ll x,ll y){
  //  cout<<x<<" "<<y<<":";
    v.clear();
    rv.clear();
    v.pb(x);
    for(ll i=x;i<=y;i++){
        ll dd=d;
        while(dd>=a[i+1]-a[i]){
            if(i==y){
                break;
            }dd-=(a[i+1]-a[i]);i++;
        }v.pb(i);
    }rv.pb(y);
    for(ll i=y;i>=x;i--){
        ll dd=d;
        while(dd>=a[i]-a[i-1]){
            if(i==x){
                break;
            }dd-=(a[i]-a[i-1]);i--;
        }rv.pb(i);
    }
   // for(ll i=0;i<v.size();i++){
   //     cout<<v[i]<<" ";
  //  }cout<<"*\n";
   // for(ll i=0;i<v.size();i++){
   //     cout<<rv[i]<<" ";
   // }cout<<"#\n";
    if(v.size()!=rv.size()){
        return 0;
    }vector<ll> w(rv.size());
    for(ll i=0;i<rv.size();i++){
        w[i]=rv[rv.size()-i-1];
    }//for(ll i=0;i<w.size();i++){
    //    cout<<w[i]<<" ";
   // }cout<<"&\n";
    for(ll i=0;i<v.size();i++){
        if(v[i]!=w[i]){
            return 1;
        }
    }return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(ll i=1;i<=n;i++){
                cin>>a[i];
            }//if(d>=a[2]-a[1]&&d<3*(d[2]-d[1]))
        }
    }else if(c<=10){
        while(t--){
            cin>>n>>d;
            ll ans=0;
            for(ll i=1;i<=n;i++){
                cin>>a[i];
            }for(ll i=1;i<=n;i++){
                for(ll j=i+1;j<=n;j++){
                    if(ok(i,j)){
                        ans++;
                    }
                }
            }cout<<ans<<"\n";
        }
    }

    return 0;
}
