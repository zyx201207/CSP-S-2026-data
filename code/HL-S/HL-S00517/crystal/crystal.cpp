#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,l=1,cost[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++)
    {
        cost[i]=cost[i-1]+(i-l+1)*(a[i]-a[i-1]);
        while(cost[i]>m)
        {
            cost[i]-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,i-l+2);
    }
    cout<<ans;
    return 0;
}
