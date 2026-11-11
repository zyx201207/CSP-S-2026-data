#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],h[N];
int main()
{
    freopen("and3.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,a[i]);
        }
        cout<<ans;
    }
    if(m==2)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    return 0;
}
