#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    vector<ll> ans(m+1);
    for(ll &i:a) cin>>i;

    for(ll i=0;i<n;i++) {
        vector<ll> c;
        for(ll j=i;j<n;j++) {
            auto pos=find(c.begin(),c.end(),a[j]);
            if(pos!=c.end()) {
                while(pos+1!=c.end()) {
                    swap(*(pos+1),*(c.end()-1));
                    c.pop_back();
                }
            } else {
                c.push_back(a[j]);
            }
            
        }

        for(ll j:c) {
            ans[j]++;
        }
    }

    for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
