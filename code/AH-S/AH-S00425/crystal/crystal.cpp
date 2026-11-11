#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,maxn=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++){
        ll sum=0,bs=1;
        for(ll j=i-1;j>=1;j--){
            sum+=(a[i]-a[j]);
            if(sum>m) break;
            bs++;
        }
        maxn=max(maxn,bs);
    }
    cout<<maxn;
    return 0;
}
