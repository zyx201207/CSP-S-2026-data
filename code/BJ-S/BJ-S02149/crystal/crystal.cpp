#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1,sum=0,ans=0;
    for(int i=2;i<=n;i++)
    {
        sum+=(r-l+1)*(a[i]-a[r]);
        r++;
        while(sum>m&&l<r)
        {
            sum-=(a[r]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
