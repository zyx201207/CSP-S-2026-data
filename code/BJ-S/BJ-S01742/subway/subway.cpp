#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll u,t;
};
ll c,n,m,d,q,w[500005];
vector<node>a[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(ll j=1;j<=k*2;j++){
            ll u,t;
            cin>>u>>t;
            a[i].push_back({u,t});
        }
    }
    while(q--){
        ll s,e,sum=0;
        cin>>s>>e;
        sum=w[s]+w[e];
        // citizhengjieyingshizuiduanludanshiwowanglezenmedadaimale
    }
    return 0;
}
