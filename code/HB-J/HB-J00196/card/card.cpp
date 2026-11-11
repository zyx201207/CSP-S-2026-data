#include<bits/stdc++.h>
using namespace std;
int a[500010];
int sum[500010];
int c[500010];
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
    int oo=0;
    for(int i=1;i<=n;i++)
    {
        oo=i;
        for(int u=i;u<=n;u++)
        {
            for(int j=1;j<=u;j++)
            {
                if(c[j]==a[u])
                {
                    for(int k=j;k<=u;k++)
                    {
                        c[k]=0;
                        oo--;
                    }
                    break;
                }
            }
            c[oo]=a[u];
            oo++;
        }
        for(int op=i;op<=oo;op++)
        {
            if(c[op]==i)
            {
                sum[i]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(sum[i]!=0)
        {
        cout<<sum[i];
        }
    }
    return 0;
}
