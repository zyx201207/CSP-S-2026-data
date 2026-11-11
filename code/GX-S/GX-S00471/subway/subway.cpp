#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 1e5+5;
ll c,n,m,d,q;
ll w[M];
struct SW{
    ll a=0,t=0;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    vector<SW> rd(n+1);
    ll rl[n+1];
    for(ll i=1;i<=n;i++){
        cin>>rl[i];
        rd.resize(rl[i]);
        for(ll j=1;j<=rl[i];j++){
            cin>>rd[j].a>>rd[j].t;
        }
    }
    ll r;
    cin>>r;
    for(ll i=1;i<=r;i++){

    }
    return 0;
}
