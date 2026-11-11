#include <bits/stdc++.h>
using namespace std;
long long f[500005],a[500005];
int n;
long long m;
bool check(int x)
{
    for(int r=x;r<=n;r++)
    {
        int l=r-x+1;
        if(a[r]*x-(f[r]-f[l-1])<=m)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+a[i];
    }
    int l=1,r=n+1,ans=0;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout << ans;
    return 0;
}
