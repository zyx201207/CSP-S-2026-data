#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200011];
    int ans=2147483647;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==m)
    {
        for(int i=1;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    if(m==n-1)
    {
        int minn=2147483647;
        for(int i=1;i<=n;i++)
        {
            minn=min(a[i],minn);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=minn) ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
