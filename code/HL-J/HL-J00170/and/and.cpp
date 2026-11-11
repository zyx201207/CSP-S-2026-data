#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxx=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
    }
    if(m==2)
    {
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxx=max(maxx,(a[i]&a[j]));
            }
        }
        cout<<maxx;
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            maxx&=a[i];
        }
        cout<<maxx;
    }
    return 0;
}
