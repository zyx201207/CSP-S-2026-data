#include<bits/stdc++.h>
using namespace std;
int a[200005],m,n,ans=INT_MAX;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
             ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
             ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
             for(int j=i+1;j<=n;j++)
             {
                 ans=max(ans,a[i]&a[j]);
             }
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1)
    {
        for(int i=1;i<=n;i++)
        {
            ans=(ans&a[i]);
        }
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,(ans^(!a[i])));
        }
        cout<<maxx;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    cout<<a[m];
}
