#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500010];
vector<ll> v,s;
bool check(ll x){
    for(ll i=0;i<ll(v.size());i++){
        if(v[i]==x) return 0;
    }
    return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(check(a[i])) v.push_back(a[i]);
        /*
        else{
            for(ll j=0;j<ll(v.size());j++){
                if(v[j]==a[i]){
                    
                }
            }
            v.push_back(a[i]);
        }
        */
    }
    return 0;
}
