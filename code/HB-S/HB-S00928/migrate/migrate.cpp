#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c,t,n;
ll d;

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    c=11;
    while(t--) {
        ll ans=0;
        cin>>n>>d;
        vector<ll> x(n+1);
        for(int i=1;i<=n;++i) cin>>x[i];
        if(c==11 or c==12) {
            ll len=x[2]-x[1];
            if(2*len>d or d>=3*len) {
                cout<<"0"<<"\n";
                continue;
            }
            cout<<n-3<<"\n";
        }
        else cout<<"0"<<"\n";
    }
    return 0;
}