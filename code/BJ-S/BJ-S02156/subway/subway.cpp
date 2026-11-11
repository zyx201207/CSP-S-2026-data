#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[507],k[507];
bool hasx[507],hasy[507],ans[507];
vector<ll> a[507],t[507];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) cin>>w[i];
    ll maxki=0;
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]>maxki) maxki=k[i];
        for(ll j=1;j<=k[i];j++){
            ll ain,tin;
            cin>>ain>>tin;
            a[i].push_back(ain);
            t[i].push_back(tin);
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
