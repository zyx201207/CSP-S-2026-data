#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,a[N],ans;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ans=a[n];
    for(ll i=n-1;i>=n-m+1;i--) ans&=a[i];
    printf("%lld\n",ans);
    return 0;
}
