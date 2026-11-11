#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200009];
vector<vector<ll>> v(39,vector<ll>(200009));
vector<ll> s(39,0);
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    vector<ll> t(200009,1);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        int b=1;
        for(int j=0;j<39;j++){
            if((b&a[i])!=0) v[j][i]=1;
            b*=2;
        }
    }
    ll ans=0,zz=1;
    for(ll i=1;i<=30;i++){
        zz*=2;
    }
    for(ll i=30;i>=0;i--){
        ll s=0;
        for(ll j=0;j<n;j++){
            if(t[j]==1&&v[i][j]==1) s++;
        }
        if(s>=k){
            ans+=zz;
            for(ll j=0;j<n;j++){
                if(v[i][j]==0) t[j]=0;
            }
        }
        zz/=2;
    }
    cout<<ans;
    return 0;
}
