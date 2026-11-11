#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
vector<bool> a[MAXN];
ll n, m;
// bool check(ll x){
//     vector<bool> v;
//     while(!x==0){
//         v.push_back(x%2);
//         x/=2;
//     }
//     for(ll i=1;i<=n;i++){

//     }
// }
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    ll minx=0;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        while(!x==0){
            a[i].push_back(x%2);
            x/=2;
        }
        minx=max(minx, ll(a[i].size()));
        
    }
    // for(ll i=1;i<=n;i++){
    //     for(ll j=0;j<a[i].size();j++){
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    vector<ll> v;
    for(ll i=1;i<=n;i++){
        ll k=minx-a[i].size();
        while(k--) a[i].push_back(0);
    }
    for(ll i=1;i<=n;i++){
        if(a[i][minx-1]==1){
            v.push_back(i);
            // cout << i << " ";
        }
    }
    ll b=0;
    if(v.size()<m){
        b=1;
        v.clear();
        for(ll i=1;i<=n;i++){
            v.push_back(i);
        }
    }
    vector<bool> ans;
    // cout << minx << endl;
    for(ll i=minx-2;i>=0;i--){
        // cout << v.size() << endl;
        if(v.size()>=m&&!b){
            ans.push_back(1);
            vector<ll> v1;
            for(ll j=0;j<v.size();j++){
                if(a[v[j]][i]){
                    v1.push_back(v[j]);
                }
            // cout << v.size() << endl;
            }
            swap(v, v1);
        }
        else{
            ans.push_back(0);
            vector<ll> v1;
            for(ll j=0;j<v.size();j++){
                if(a[v[j]][i]){
                    v1.push_back(v[j]);
                }
            // cout << v.size() << endl;
            }
            if(v1.size()>=m) b=0;
        }

    }
    if(v.size()>=m) ans.push_back(1);
    else ans.push_back(0);
    ll Ans=0;
    ll k=1;
    for(ll i=ans.size()-1;i>=0;i--){
        Ans+=ans[i]*k;
        k*=2;
    }
    cout <<Ans;
}