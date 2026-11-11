#include <iostream>
#include <cstdio>
using namespace std;
long long a[500001]={};
long long b[500001]={};
long long c[500001]={};
long long l,n,m;
long long find(long long x,long long i1)
{
    for(long long i=0;i<=i1;++i)
    {
       if(b[i]==x)
       {
           return i;
       }
       if(b[i]==0)
       {
           return -1;
       }
    }
    return -1;
}
void mn(long long i)
{
    long long i1=0;
    while(i<n)
    {
        if(find(a[i],i1)!=-1)
        {
            i1=find(a[i],i1);
        }
        b[i1]=a[i];
        i1++;
        i++;
    }
    l=i1;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        mn(i);
        for(int j=1;j<=m;++j)
        {
            if(find(j,l)!=-1)
            {
                c[j]++;
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        cout<<c[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
