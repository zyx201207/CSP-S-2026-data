#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const ll maxn=5e5+5;
ll c,n,m,d,q,w[maxn],k[maxn];
vector<ll> a[maxn],t[maxn];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            ll x,y;cin>>x>>y;
            a[i].pb(x);t[i].pb(y);
        }
    }
    if(n==1){
        while(q--){
            ll x,y;cin>>x>>y;ll p,q;
            for(ll i=0;i<a[1].size();i++){
                if(a[1][i]==x){
                    p=i;
                }if(a[1][i]==y){
                    q=i;
                }
            }
            cout<<w[x]+w[y]+t[1][p]+t[1][q]<<"\n";
        }
    }else if(n==2){
        while(q--){
            ll x,y;cin>>x>>y;ll p,q;
            for(ll i=0;i<a[1].size();i++){
                if(a[1][i]==x){
                    p=i;
                }if(a[1][i]==y){
                    q=i;
                }
            }
            cout<<w[x]+w[y]+t[1][p]+t[1][q]<<"\n";
        }
    }else if(1){
        while(q--){
            ll x,y;cin>>x>>y;

        }
    }

    return 0;
}
