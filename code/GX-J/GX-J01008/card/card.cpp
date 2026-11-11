#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long sum[m+2]={0};
    long long a[n+2];
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        long long s[m+2]={0};
        for(long long j=i;j<=n;j++)
        {
            if(s[a[j]]!=0)
            {
                for(long long l=s[a[j]];l<j;l++)
                {
                    s[a[l]]=0;
                }
            }
            s[a[j]]=j;
        }
        for(long long i=1;i<=m;i++)
        {
            if(s[i]!=0)
            {
                sum[i]++;
            }
        }
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<sum[i]<<" ";
    }
    return 0;
}
