#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[500010],n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            b[i]=a[i];
        }
        else
        {
            b[i]=a[i]+b[i-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            c[i]=1;
        }
        else
        {
            c[i]=a[i]*(i-1)-b[i-1];
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(m>=c[i])
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
