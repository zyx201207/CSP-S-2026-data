
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
bool f[300005];
ll ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        vector<ll> v;
        for(ll j=i;j<=n;j++){
           for(ll k=0;k<v.size();k++){
                if(v[k]==a[j])v.erase(v.begin()+k,v.end());
            }
            v.push_back(a[j]);
        }
        for(ll i=0;i<v.size();i++){
            ans[v[i]]++;
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
