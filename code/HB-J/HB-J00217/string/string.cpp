#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,char>>v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    ll ans = 0;
    cin>>n;
    v.resize(n);
    for(ll i = 0;i < n;i++){
        ll num;
        char c;
        cin>>num>>c;
        v[i].first = num;
        v[i].second = c;
    }
    ll l = 0;
    ll r = n - 1;
    ll lp = v[l].first;
    ll rp = v[r].first;
    while(l < r){
        if(v[l].second == v[r].second){
            if(lp > rp){
                lp = lp - rp;
                r--;
                rp = v[r].first;
            }
            else if(lp < rp){
                rp = rp - lp;
                l++;
                lp = v[l].first;
            }
            else{
                l++;
                r--;
                ll lp = v[l].first;
                ll rp = v[r].first;
            }
        }
        else{
            if(lp > rp){
                ans = ans + lp - rp;
                lp = lp - rp;
                r--;
                rp = v[r].first;
            }
            else if(lp < rp){
                ans = ans + rp - lp;
                rp = rp - lp;
                l++;
                lp = v[l].first;
            }
            else{
                ans = ans + lp;
                l++;
                r--;
                ll lp = v[l].first;
                ll rp = v[r].first;
            }
        }
    }
    cout<<ans;
    return 0;
}
