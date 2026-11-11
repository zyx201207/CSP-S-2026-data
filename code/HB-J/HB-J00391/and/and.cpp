#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,m,a[N],ans=0,f[N],cnt,k;

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i],f[i]=1;
    for (int i=30;i>=0;i--)
    {
        k=1ll<<i;
        cnt=0;
        for (int j=1;j<=n;j++)
            if ((a[j]&k)&&f[j]) cnt++;
        if (cnt>=m)
        {
            ans+=k;
            for (int j=1;j<=n;j++) if (!(a[j]&k)) f[j]=0;
        }
    }
    cout<<ans;
    return 0;
}
