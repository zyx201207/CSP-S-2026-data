#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,k,w[500005],a[505][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k;
        for(ll j=1;j<=k;j++) cin>>a[k][j];
    }
    for(ll i=1;i<=q;i++){
        ll l,r,s=0;
        cin>>l>>r;
        cout<<(w[l]+w[r])*2;
    }
    return 0;
}
