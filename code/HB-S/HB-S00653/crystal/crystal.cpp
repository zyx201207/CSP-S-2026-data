#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[550000],b[550000];
int main(){
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    for(ll i=n-1;i>=1;i--){
        for(ll j=1;j<=n-i;j++){
            ll num=0;
            for(ll k=j;k<=j+i-1;k++){
                num+=b[k]*k;
            }
            if(num<=m){
                cout<<i+1;
                return 0;
            }
        }
    }
    return 0;
}
