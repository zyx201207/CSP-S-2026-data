#include <bits/stdc++.h>
using namespace std;
int a[200005];
int hs(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(a[i]-a[i-1]!=1)
            return false;
    }
    return true;
}
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==2)
    {
        int maxn=0,mx=0,k;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>maxn)
            {
                maxn=a[i];
                k=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>mx&&i!=k)
            {
                mx=a[i];
            }
        }
        maxn&=mx;
        cout<<maxn;
    }
    else if(m==n-1)
    {
        sort(a+1,a+n+1);
        int ans=a[n];
        for(int i=n-1;i>=2;i--)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(n<=20)
    {
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int sum=a[i];
            for(int j=i+1;j-i+1<=m;j++)
            {
                sum&=a[j];
            }
            ans=max(sum,ans);
        }
        cout<<ans;
    }
    else if(hs(n))
    {
        cout<<n-m;
    }
    else
    {
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    return 0;
}
