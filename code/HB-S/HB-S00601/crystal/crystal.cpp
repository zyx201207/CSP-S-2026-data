#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,cost=0,ans=0;
    for(int i=2;i<=n;i++)
    {
        cost+=(i-l)*(a[i]-a[i-1]);
        while(l<i&&cost>m)
        {
            cost-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
