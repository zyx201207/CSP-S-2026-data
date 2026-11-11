#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],sum;
int n,m,ans=INT_MIN;
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
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else
    {
        sort(a+1,a+n+1);
        int k=a[n],k1=a[n-1];
        for(int i=n-1;i>n-m;i--)
        {
            k&=a[i];
        }
        for(int i=n-2;i>n-m-1;i--)
        {
            k1&=a[i];
        }
        ans=max(k,k1);
    }
    cout<<ans;
}
