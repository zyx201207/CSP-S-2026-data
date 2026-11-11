#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int s[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=m-i*a[i]+s[i];
        // cout<<x<<'\n';
        int l=0,r=i-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(-mid*a[i]+s[mid]<=x)
            {
                ans=max(ans,i-mid);
                // cout<<i<<' '<<mid<<'\n';
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    cout<<ans;
}//14:44