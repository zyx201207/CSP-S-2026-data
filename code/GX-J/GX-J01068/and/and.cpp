#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   int n,m,i,max=-100,big=-100,c,x;
   cin>>n>>m;
   for(i=1;i<=n;i++) cin>>a[i];
   if(m==1)
   {
       for(i=1;i<=n;i++)
       {
           if(max<a[i]) max=a[i];
       }
       cout<<max;
       return 0;
   }
   if(m==2)
   {
       for(i=1;i<=n;i++)
       {
           if(max<a[i])
           {
               max=a[i];
               x=i;
            }
       }
       a[x]=0;
       for(i=1;i<=n;i++)
       {
           if(big<a[i]) big=a[i];
       }
       c=max&big;
       cout<<c;
       return 0;
   }
    for(i=1;i<=n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
            x=i;
        }
    }
    a[x]=0;
    for(i=1;i<=n;i++)
    {
        if(big<a[i])
        {
            big=a[i];
            x=i;
            }
    }
    a[x]=0;
    c=max&big;m-=2;
    while(m--)
    {
        max=-100;
        for(i=1;i<=n;i++)
        {
            if(max<a[i])
            {
                max=a[i];
                x=i;
            }
        }
        a[x]=0;
        c=c&max;
    }
    cout<<c;
   return 0;
}
