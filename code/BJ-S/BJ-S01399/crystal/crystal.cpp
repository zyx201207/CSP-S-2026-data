#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005],b[500005],c[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        b[i] = a[i+1]-a[i];
        c[i] = b[i] + c[i-1];
    }
    b[n] = 1e18+10;
    ll ans = 0,cost = 0;
    for(ll l=0,r=0;r<=n;){
        while(r<n && cost + b[r]*(r-l+1) <= m){
            cost += b[r]*(r-l+1);
            r++;
            //cout<<"l:"<<l<<" r:"<<r<<" cost:"<<cost<<'\n';
            ans = max(ans,r-l+1);
        }
        if(r == n){
            break;
        }
        if(l<=r){
            cost -= c[r-1] - c[l-1];
            l++;
        }
    }
    cout<<ans;
} 