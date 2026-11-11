#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q;
ll w[500010],k[510],x[100010],y[100010],a[510][50010],t[510][50010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
    }
    for(ll i=1;i<=q;i++){
        ll ans=0;
        cin>>x[i]>>y[i];
        ans+=w[x[i]]+w[y[i]];
        ans+=2*t[1][1]+2*t[1][2];
        cout<<ans<<endl;
    }
    return 0;
}
