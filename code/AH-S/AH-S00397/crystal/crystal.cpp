#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],l=1,r=1,s,maxx;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    a[0]=a[1];
    for(ll i=1;i<=n;i++)
        b[i]=a[i]-a[i-1];
    for(ll i=1;i<=n;i++)
    {
        s+=(r-l)*b[r];
        while(s>m&&l<=r)
        {
            s-=(a[r]-a[l+1]);
            l++;
        }
        maxx=max(maxx,r-l+1);
        r++;
    }
    cout<<maxx;
    return 0;
}
