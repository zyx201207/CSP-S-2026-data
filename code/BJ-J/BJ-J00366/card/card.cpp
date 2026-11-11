#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long c[50005],a[50005];
long long cnt[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long top=0;
    for(long long i=1;i<=n;i++)
    {
        memset(c,0,n);
        top=0;
        for(long long j=i;j<=n;j++)
        {
            for(long long k=1;k<=top;k++)
            {
                if(c[k]==a[j])
                {
                    top=k-1;
                }
            }
            top+=1;
            c[top]=a[j];
        }
        for(long long z=1;z<=top;z++)
        {
            for(long long y=1;y<=m;y++)
            {
                if(c[z]==y)cnt[y]++;
            }
        }
    }
    int sum=0;
    for(long long i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
