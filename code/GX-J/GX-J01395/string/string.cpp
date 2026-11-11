#include<bits/stdc++.h>
using namespace std;
long long n,a[200005]={0},ans=0,aa;
char z[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long nn=n,ii=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>z[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(z[ii]!=z[nn])
        {
            if(a[ii]>a[nn])
            {
                a[ii]-=a[nn];
                ans+=a[nn];
                a[nn]=0;
                nn--;
            }
            else if(a[ii]==a[nn])
            {
                ans+=a[nn];
                a[ii]=0;a[nn]=0;
                ii++;nn--;
            }
            else
            {
                ans+=a[ii];
                a[nn]-=a[ii];
                a[ii]=0;
                ii++;
            }
         }
         else if(z[ii]==z[nn]&&ii!=nn)
         {
            if(a[ii]>a[nn])
            {
                a[ii]-=a[nn];
                a[nn]=0;
                nn--;
            }
            else if(a[ii]==a[nn])
            {
                a[ii]=0;a[nn]=0;
                ii--;nn++;
            }
            else
            {
                a[nn]-=a[ii];
                a[ii]=0;
                ii++;
            }
         }
         if(ii>=nn)
         {
             break;
         }
    }
    cout<<ans;
    return 0;
}

