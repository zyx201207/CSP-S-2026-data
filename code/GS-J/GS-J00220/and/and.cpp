#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if (m==1)
    {
        cout<<a[0];
        return 0;
    }
    if (m==n)
    {
        ans=15;
        for (int i=0;i<n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    for (int i =0;i<n;i++)
    {
       for (int j=0;j<n;j++)
       {
           ans=max (ans,a[i]&a[j]);
       }
    }
    cout<<ans;
    return 0;
}

