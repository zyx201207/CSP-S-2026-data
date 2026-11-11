#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],s[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll ans=0;
    for(ll r=1,l=1;r<=n;r++)
    {
        while(l<=r&&(r-l+1)*a[r]-(s[r]-s[l-1])>m) l++;
        if(l<=r) ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
