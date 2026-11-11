#include <bits/stdc++.h>

using namespace std;

int a[2000005];

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    if(m==2)
    {
        int maxx=-1;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]&a[j]>maxx)
                {
                    maxx=a[i]&a[j];
                }
            }
        }
        cout<<maxx;
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
    if(m==n-1)
    {
        int maxx=-1;
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                int ans=a[2];
                for(int j=3;j<=n;j++)
                {
                    ans&=a[j];
                }
                if(ans>maxx)
                {
                    maxx=ans;
                }
            }
            else
            {
                int ans=a[1];
                for(int j=2;j<=n;j++)
                {
                    if(i!=j)
                    {
                        ans&=a[j];
                    }
                }
                if(ans>maxx)
                {
                    maxx=ans;
                }
            }
        }
        cout<<maxx;
    }
    return 0;
}
