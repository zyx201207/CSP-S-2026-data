#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    long long n,m;
    cin>>n>>m;
    if(n>500000 || m>300000) return 0;
    long long a[n+5],c[m+5]={0};
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(long long i=1;i<=n;i++)
    {
        long long b[n+5]={0};
        for(long long j=i;j<=n;j++)
        {
            b[j]=a[j];
            if(j>i)
            {
                for(long long k=i;k<n;k++)
                {
                    if(b[j]==b[k])
                    {
                        for(long long g=k;g<j;g++)
                        {
                            b[g]=0;
                        }
                    }
                }
            }

        }
        for(long long j=i;j<=n;j++)
        {
            c[b[j]]++;
        }
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
