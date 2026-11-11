#include <bits/stdc++.h>
using namespace std;
long long a[500050],s[500050],n,m,ans;
bool chk(int x)
{
    for(int i=x;i<=n;i++)
    {
        int j=i-x+1;
        int dc=s[i]-s[j-1];
        int ned=x*a[i];
        if(ned-dc<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(chk(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
