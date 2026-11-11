#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l,m=1,o=0,sum=0;
    cin>>n;
    int a[200000];
    double p[200000],k[200000];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>p[i];
    }
    for(int i=1;i<=n;i++)
    {
         o=a[i];
        for(int l=m;l<=o;l++)
        {
            k[l]=p[i];
        }
        m=l;
    }
    for(int l=m;l>0;l--)
    {
          if(k[l]!=k[m-l+1])
            sum++;
    }
    cout<<sum;
}
