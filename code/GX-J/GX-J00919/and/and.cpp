#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long m[50005];
long long v[50005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n=0;
    long long f=0;
    long long d1=0;
    long long d2=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=d1)
        {
            d2=d1;
            d1=a[i];
        }
    }
    sort(a+1,a+1+n);
    long long c=1;
    while(1)
    {
        m[c]=d1%2;
        c++;
        d1=d1/2;
        if(d1==0)
        {
            break;
        }
    }
    long long g=1;
    while(1)
    {
        v[g]=d2%2;
        g++;
        d2=d2/2;
        if(d2==0)
        {
            break;
        }
    }
    for(long long i=0;i<min(c,g);i++)
    {
        if(m[c-i]==v[g-i]&&m[c-i]==1)
        {
            if(i==0)
            {
                f=f+1;
            }
            else
            {
                int p=2;
                for(long long j=1;j<=i;j++)
                {
                    p=p*2;

                }
                f=f+(p/2);
            }
        }
    }
    cout<<f+1;
    return 0;

}

