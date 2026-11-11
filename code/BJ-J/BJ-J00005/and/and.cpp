#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int main(){
    ll n,m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=a[n];
    cout<<a[n]<<" ";
    for(ll i=n-1;i>=n-m+1;i--)
        ans&=a[i];
    cout<<ans;
    return 0;
}
