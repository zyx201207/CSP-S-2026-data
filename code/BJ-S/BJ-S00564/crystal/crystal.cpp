#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[555555];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        if(m<(i-1)*(a[i]-a[i-1]))
        {
            cout<<i-1;
            return 0;
        }
        m-=(i-1)*(a[i]-a[i-1]),a[i-1]=a[i];
    }
    cout<<n;
    return 0;
}
