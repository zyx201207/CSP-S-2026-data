#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int n1=a[n-2],n2=a[n-1],n3=a[n];
    if(n==1)
    {
        if(n3==1)
        {
            cout<<1<<" "<<0;
        }
        else
        {
            cout<<0<<" "<<1;
        }
    }
    if(n==2)
    {
        if(n2==1&&n3==1)
        {
            cout<<2<<" "<<1;
        }
        if(n2==1&&n3==2)
        {
            cout<<1<<" "<<2;
        }
        if(n2==2&&n3==1)
        {
            cout<<2<<" "<<1;
        }
        if(n2==2&&n3==2)
        {
            cout<<0<<" "<<2;
        }
    }
    if(a[n-2]==1&&a[n-2]==1&&a[n-2]==1)
    {
        cout<<n<<" "<<0;
    }
    if(a[n-2]==1&&a[n-2]==1&&a[n-2]==2)
    {
        cout<<n-1<<" "<<n;
    }
    if(a[n-2]==1&&a[n-2]==2&&a[n-2]==1)
    {
        cout<<n<<" "<<1;
    }
    if(a[n-2]==2&&a[n-2]==1&&a[n-2]==1)
    {
        cout<<n<<" "<<0;
    }
    if(a[n-2]==1&&a[n-2]==2&&a[n-2]==2)
    {
        cout<<0<<" "<<n;
    }
    if(a[n-2]==2&&a[n-2]==1&&a[n-2]==2)
    {
        cout<<1<<" "<<n;
    }
    if(a[n-2]==2&&a[n-2]==2&&a[n-2]==1)
    {
        cout<<n<<" "<<n-1;
    }
    if(a[n-2]==2&&a[n-2]==2&&a[n-2]==2)
    {
        cout<<0<<" "<<n;
    }
    return 0;
}

