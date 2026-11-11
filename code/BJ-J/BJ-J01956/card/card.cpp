#include<bits/stdc++.h>
int n,m,pos,a[200001],q[200001],b[200001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        std::cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        pos=1;
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=pos;k++)
            {
                if(q[k]==a[j])
                {
                    pos=k;
                }
            }
            if(q[pos]!=a[j])
            {
                q[++pos]=a[j];
            }
        }
        for(int j=1;j<=pos;j++)
        {
            b[q[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        std::cout<<b[i]<<" ";
    }
    return 0;
}
