#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005];
vector<ll> v;
map<ll,ll> mp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++){
        v.resize(0);
        for(ll j=i;j<=n;j++){
            bool b=0;
            for(auto k=0;k<v.size();k++){
                if(v[k]==a[j]||b==1){
                   b=1;
                   v[k]=0;
                }
            }
            v.push_back(a[j]);
        }
        for(auto j:v){
            mp[j]++;
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<mp[i]<<' ';
    }
    return 0;
}
