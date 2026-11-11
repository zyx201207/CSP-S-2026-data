#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxm=0;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1) ;
        cout<<a[n];
    }
    else if(m==2)
    {
         int maxa=0;
         for(int i=1;i<=n;i++)
         {
             for(int j=i;j<=n;j++)
             {
                 if(i|j>maxa) maxa=a[i]|a[j];
             }
         }
         cout<<maxa;
    }
    else if(m==n-1)
    {
        int maxa=0;
        for(int i=1;i<=n;i++)
        {
            int maxb=0;
            for(int j=1;j<=n;i++)
            {
                if(j!=i)
                {
                    maxb=maxb|a[j];
                }
            }
            if(maxb>maxa) maxa=maxb;
        }
        cout<<maxa;
    }
    else if(m==n)
    {
        int maxa=a[1];
        for(int i=2;i<=n;i++)
        {
            maxa=maxa|a[i];
        }
        cout<<maxa;
    }
}
