#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],coun[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int t=1;
    while(t<=n)
    {
        int now[500005],k=0;
        for(int i=1;i<=m;i++)
        {
            now[i]=0;
        }
        for(int i=t;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(now[j]==a[i])
                {
                    k=j-1;
                    break;
                }
            }
            now[++k]=a[i];
        }
        for(int i=1;i<=k;i++)
        {
            coun[now[i]]++;
        }
        t++;
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",coun[i]);
    }
    return 0;
}