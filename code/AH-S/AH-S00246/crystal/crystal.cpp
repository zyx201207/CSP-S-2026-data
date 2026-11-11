#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int b[n+1];
    int c[n+1];
    int bb=1;
    int cc=1;
    b[1]=a[1];
    c[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(b[bb]!=a[i])
        {
            b[bb]=a[i];
            bb++;
            cc++;
            continue;
        }
        c[cc]++;
    }
    int biaoji;
    for(int i=2;i<=cc;i++)
    {
        if(c[i]>c[i-1])
        {
            biaoji=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==c[biaoji])
        {
            if(a[i]==c[biaoji+1])
            {
                continue;
            }
            else
            {
                biaoji=i;
            }
        }
    }
    int x=biaoji;
    int sum=0;
    for(int i=x;i>0;i--)
    {
        if(sum>m)
        {
            sum-=(a[x]-a[i+1]);
            break;
        }
        sum+=(a[x]-a[i]);
    }
    cout<<sum;
    return 0;
}
