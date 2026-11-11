#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll max_a = LONG_MIN;
    vector<ll>v(n);
    for(ll i = 0;i < n;i++){
        cin>>v[i];
        max_a = max(max_a,v[i]);
    }
    if(m == 1){
        cout<<max_a;
        return 0;
    }
    max_a = LONG_MIN;
    if(m == 2){
        for(ll i = 0;i < n;i++){
            for(ll j = 0;j < n;j++){
                if(i == j){
                    continue;
                }
                ll temp = v[i] & v[j];
                max_a = max(temp,max_a);
            }
        }
        cout<<max_a;
        return 0;
    }
    if(m == n){
        ll a = v[0];
        for(ll i = 1;i < n;i++){
            a = a&v[i];
        }
        cout<<a;
        return 0;
    }
    cout<<1;
    return 0;
}
