#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,d[1000000],m,a[100000],b[100000],l[100000]={0},h=1,g=0,x=0,z,v;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>d[i];
    }
    m=1;
    for(long long i=1;i<n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            z=d[i];
            v=d[j];
            for(long long k=0;k<=40;k--)
            {
                a[k]=d[i]%2;
                z/=2;
            }
            for(long long k=0;k<=40;k--)
            {
                b[k]=d[j]%2;
                v/=2;
            }
            for(long long k=0;k<=40;k--)
            {
                if(a[k]==1&&b[k]==1)
                {
                    l[k]=1;
                }
            }
            for(long long k=0;k<=40;k--)
            {
                if(l[k]==1)
                {
                    for(long long y=1;y<=k;y++)
                    {
                        h*=2;
                    }
                    m+=h;
                    h=1;
                }
            }
            if(m>x)
            {
                x=m;
            }
            m=1;
        }
    }
    cout<<x;


    return 0;
}
