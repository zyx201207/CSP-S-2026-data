#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N],sa[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
    ll l=1,ans=0;
    for(ll r=1;r<=n;r++)
    {
        while(l < r && a[r]*(r-l+1)-(sa[r]-sa[l-1]) > m) l++;
        if(a[r]*(r-l+1)-(sa[r]-sa[l-1])<=m)
            ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
