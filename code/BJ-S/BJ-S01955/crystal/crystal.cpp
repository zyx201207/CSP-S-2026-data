#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int lst=1,ans=1;
    long long sm=0;
    for(int i=2;i<=n;i++)
    {
        sm+=(i-lst)*(a[i]-a[i-1]);
        while(lst<=n&&sm>m)
            sm-=a[i]-a[lst],lst++;
        ans=max(ans,i-lst+1);
    }
    cout<<ans<<"\n";
}
