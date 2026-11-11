#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++){
        s[i]=(a[i]-a[i-1])*(i-1)+s[i-1];
    }
    ll in=0;
    for(ll i=1;i<n;i++){
        if(s[i]<=m&&m<=s[i+1]){
            in=i;
        }
    }
    if(m>=s[n]){
        in=n;
    }
    cout<<in;
    return 0;
}
