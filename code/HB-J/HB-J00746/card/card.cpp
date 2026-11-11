#include <bits/stdc++.h>
using namespace std;
int sum[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int c[500005],k;
        for(int j=i;j<=n;j++)
        {
            c[j]=a[j];
        }
        for(int j=i;j<=n;j++)
        {
            int y=0;
            for(int o=j-1;o>=i;o--)
            {
                if(c[j]==c[o])
                {
                    y=1;
                    k=o;
                    break;
                }
            }
            if(y==1)
            {
                for(int o=k;o<j;o++)
                {
                    c[o]=-1;
                }
            }
        }
        for(int j=i;j<=n;j++)
        {
            for(int g=1;g<=m;g++)
            {
                if(c[j]==g)
                {
                    sum[g]++;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<sum[m]<<" ";
    }
}
