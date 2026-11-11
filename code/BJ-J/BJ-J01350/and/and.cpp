#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[200005];
vector<ll>wei[50];
vector<ll>v;
ll maxn=0;
void Idk(ll n){

    for(ll i=1;(1<<i)<=n;i++){

        if(n&(1<<(i-1))){
            wei[i].push_back(n);
        }
        maxn=max(maxn,i);
    }
}
void cr(ll n){
    for(auto v1:wei[n]){
        if(find(v.begin(),v.end(),v1)==v.end()){
            swap(v1,wei[n].back());
            wei[n].pop_back();
        }
    }
}
ll ans=(ll)(1<<31)-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        Idk(a[i]);
        v.push_back(a[i]);
    }
    for(ll i=maxn;i>=1;i--){
        cr(i);
        if(wei[i].size()<m)continue;
        v.clear();
        for(auto v1:wei[i]){
            v.push_back(v1);
        }
        if(v.size()==m)break;
    }
    for(auto v1:v){
        ans&=v1;
    }
    cout<<ans;
    return 0;
}
