#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

ll tc(vector<ll> &v,ll m){
    int k = m / (v[1] - v[0]);
    return (ll)sqrt(2 * k);
}

ll crs(vector<ll> &v,ll m){
    vector<ll> d(v.size());
    d[0] = v[0];
    for(int i = 1;i < v.size();i++){
        d[i] = v[i] - v[i - 1];
    }
    ll ms = 0;
    ll us = 0;
    for(ll i = 0;i < v.size();i++){
        for(ll j = i + 1;j < v.size();j++){
            ll cm = 0;
            ll cu = 0;
            for(ll k = i + 1;k <= j;k++){
                cm += (k - 1 - i) * d[k];
                cu++;
                if(cm > m){
                    break;
                }
            }
            if(cm < m && cu > us){
                ms = cm;
                us = cu;
            }
        }
    }
    return us + 1;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    scanf("%lld %lld",&n,&m);
    vector<ll> v(n);
    bool flag = true;
    bool f2 = true;
    for(ll i = 0;i < n;i++){
        scanf("%lld",&v[i]);
        if(v[i] != v[0]){
            flag = false;
        }
        if(i == 0 || i == 1){
            continue;
        }else{
            if(v[i] - v[i] - 1 != v[i - 1] - v[i - 2]){
                f2 = false;
            }
        }
    }
    if(flag){
        printf("%lld\n",(m == 0) ? n : m);
        return 0;
    }
    if(f2){
        printf("%lld\n",tc(v,m));
        return 0;
    }
    sort(v.begin(),v.end());
    printf("%lld\n",crs(v,m));
    return 0;
}
