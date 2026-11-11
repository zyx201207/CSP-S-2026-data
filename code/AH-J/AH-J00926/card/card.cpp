#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
    }else{
        cout<<n/2<<" "<<(n+1)/2;
    }
    return 0;
}
