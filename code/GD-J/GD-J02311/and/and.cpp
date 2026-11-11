#include<bits/stdc++.h>
using namespace std;
int n,a[10005],m,maxj;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
        cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==m)
    {
        maxj=a[n];
        for(int i=1;i<=n-1;i++)
        {
            maxj=maxj&&a[i];
        }
        cout<<maxj;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;i++)
            {
                int c=a[i]&&a[j];
                 if(c>maxj)maxj=c;
            }
        }
    }
    else if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            int w=a[i]&&a[i];
            if(w>maxj)maxj=w;
        }

    }
    int sum=0,s=1;
   while(maxj>0)
   {
       sum=sum+s;
       s*=2;
       maxj--; 
   }
   cout<<sum;
    return 0;
}
