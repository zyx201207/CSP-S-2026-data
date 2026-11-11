#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],maxn=0;
ll fun(ll i,ll m,ll sum){
    for(ll j=i+1;j<=i+m;j++){
        fun(j,m-1,sum&=a[j]);
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        maxn=max(maxn,fun(i,m,a[i]));
    }
    cout<<maxn;
    return 0;
}
