#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],d[500005],sum[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int f=i-1;
        for(int j=i;j<=n;j++)
        {
            f++;
            if(d[a[j]]!=0)
            {
                for(int k=d[a[j]];k<=j;k++)
                {
                    d[b[k]]=0;
                    b[k]=0;
                    f=d[a[j]];
                }
            }
            if(d[a[j]]==0)
            {
                d[a[j]]=f;
                b[f]=a[j];
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(d[j]>=0)
            {
                sum[j]++;
            }
        }
        for(int j=i;j<=n;j++)
        {
            d[b[j]]=0;
            b[j]=0;

        }
    }
    for(int i=1;i<=m;i++)
        cout<<sum[i]<<" ";
    return 0;
}
