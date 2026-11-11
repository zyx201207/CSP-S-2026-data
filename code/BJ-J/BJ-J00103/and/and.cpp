#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
long long sd[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>sd[i];
    }
    if(m==1)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,sd[i]);
        }
        cout<<ans<<"\n";
    }
    else if(m==2)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,sd[i]&sd[j]);
            }
        }
        cout<<ans<<"\n";
    }
    else if(m==n)
    {
        long long ans=sd[1];
        for(int i=2;i<=n;i++)
        {
            ans&=sd[i];
        }
        cout<<ans<<"\n";
    }
    else
    {
        int flag=true;
        for(int i=1;i<=n;i++)
        {
            if(sd[i]!=i-1)
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
        {
            long long ans=sd[n];
            for(int i=2;i<=m;i++)
            {
                ans&=sd[n-i+1];
            }
            cout<<ans<<"\n";
        }
        else
        {
            sort(sd+1,sd+1+n);
            long long ans=sd[n];
            for(int i=2;i<=m;i++)
            {
                ans&=sd[n-i+1];
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}