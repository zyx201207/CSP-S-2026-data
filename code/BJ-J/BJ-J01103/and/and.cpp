#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int abb;
    if(m==1)
    {
        int Max=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            Max=max(Max,x);
        }
        abb=Max;
        cout<<Max;
    }
    else if(m==n)
    {
        int ans;
        int x;
        cin>>x;
        ans=x;
        for(int i=2;i<=n;i++)
        {
            cin>>x;
            ans=ans&x;
        }
        cout<<ans;
    }
    else if(m==2)
    {
        long long a[2005]={};
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                long long cnt=a[i]&a[j];
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        cout<<ans;
    }
    else
    {
        cout<<abb;
    }
    return 0;
}