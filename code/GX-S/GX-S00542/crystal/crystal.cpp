#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,ans=1,an=0,ma=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<ll> a;
    for(ll i=0;i<n;i++){
        cin>>q;
        a.push_back(q);
    }
    sort(a.begin(),a.end());
    for(ll j=0;j<n-ma+5;j++){
        for(ll i=j+ma;i<n;i++){
            q=an;
            an=((i-j)*(a[i]-a[i-1]))+an;
            if(an>m){
                break;
            }
            ans=i+1-j;
        }
        an=an-(a[j+ma-1]-a[j]);
        ma=max(ma,ans);
    }
    cout<<ma;
    return 0;
}
