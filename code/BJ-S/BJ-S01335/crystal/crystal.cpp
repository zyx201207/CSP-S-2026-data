#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],d[500005],l=2,cost,cur,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        d[i]=a[i]-a[i-1];
    }
    for (int i=2;i<=n;++i)
    {
        cost+=(i-l+1)*d[i];
        while(cost>m)
        {
            cost-=(a[i]-a[l-1]);
            ++l;
        }
        ans=max(ans,i-l+2);
    }
    cout<<ans<<endl;
    return 0;
}