#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll ans=a[n];
    for(ll i=n-1;i>n-m;i--)ans&=a[i];
    cout<<ans;
    return 0;
}
