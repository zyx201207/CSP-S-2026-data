#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
vector<ll> a;

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    a.resize(n);
    for(ll &i:a) cin>>i;
    sort(a.begin(),a.end(),[](ll a,ll b){return a>b;});
    
    ll ans=a[0];
    for(ll i=1;i<m;i++) {
        ans&=a[i];
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
