#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,a[i]);
        }
    }
    if(m==2)
    {

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                int s=a[i]&a[j];
                mx=max(mx,s);
            }
        }
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            mx&=a[i];
        }
    }
    if(m==n-1)
    {
        int s=a[1];
        for(int i=2;i<=n;i++)
        {
            s&=a[i];
        }
        for(int i=1;i<=n;i++)
        {
            int s1=s&a[i];
            mx=max(mx,s1);
        }
    }
    cout<<mx;
    return 0;
}
