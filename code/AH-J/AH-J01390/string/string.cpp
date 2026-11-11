#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vector<pair<ll,char>> fs(n);
    for(auto &x:fs) cin>>x.first>>x.second;
    ll l=0,r=n-1,ans=0;
    while(l<r){
        if(fs[l].first==fs[r].first){
            if(fs[l].second!=fs[r].second) ans+=fs[l].first;
            l++,r--;
        }else if(fs[l].first<fs[r].first){
            if(fs[l].second!=fs[r].second){
               ans+=fs[l].first;
            }
            fs[r].first-=fs[l].first;
            l++;
        }else{
            if(fs[l].second!=fs[r].second){
               ans+=fs[r].first;
            }
            fs[l].first-=fs[r].first;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
//pdboynbkls
