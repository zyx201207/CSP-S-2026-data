#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll c, n, m, d, q;

void solve(){
    cin>>c>>n>>m>>d>>q;
    vector<ll>w(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    ll a[505],t[505];
    vector<ll >e;
    for(int i=1;i<=n;i++){
        ll k=0;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];

            e[a[j]]=t[i];
        }
    }
    vector<ll>x(q+1,0),y(q+1,0);
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++){
        ll s=0;
        s+=w[x[i]];
        s+=w[y[i]];
        s+=e[x[i]];
        s+=e[y[i]];
        cout<<s<<"\n";
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll _=1;
    while(_--)solve();
    return 0;
}
