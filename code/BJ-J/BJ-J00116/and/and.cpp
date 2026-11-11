#include <bits/stdc++.h>
using namespace std;
int n,a[200005],m,f[200005],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    ans=a[1];
    if(m==1)
    {
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans;
    }
    else if(m==n)
    {
        for(int i=1;i<=n;i++) ans=ans&a[i];
        cout<<ans;
    }
    else
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans;
    }
    return 0;
}
