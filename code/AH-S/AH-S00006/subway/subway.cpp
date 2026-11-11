#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,d,q,a[500010],x,y;
struct node{
    ll v,w;
    operator >();queu
};
vector<node> e[500510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>t>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll v,t;
            cin>>v>>t;
            e[m+i].push_back({v,t});
            e[v].push_back({m+i,t});
        }
    }
    while(q--){
        cin>>x>>y;

    }
    return 0;
}
