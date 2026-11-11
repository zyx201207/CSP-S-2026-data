#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll c,t,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(ll i=1;i<=t;i++){
        ll n,d;
        cin<<n<<d;
        for(ll j=1;j<=n;j++) cin>>a[i];
    }
    for(ll i=1;i<=t;i++) cout<<a[i]<<"\n";
    return 0;
}
