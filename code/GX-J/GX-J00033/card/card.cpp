#include<bits/stdc++.h>
using namespace std;
int a[1000010],n,m,vis[1000010],b[1000010],pt=1,tmp1,bo=1,tmp2,z=1;
bool bl(int z)
{
    for(z=1;z<=n;z++)
    {
        if(b[z]==a[tmp2]) return false;
    }
    return 1;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            tmp2=j;
            if(!bl(z))
            {
                b[pt]=a[j];
                pt++;
            }
            else
            {
                for(int k=1;k<=n;k++)
                {
                    if(b[k]==a[j])
                    {
                        for(int g=k;g<=n;g++)
                        {
                            b[g]=0;
                        }
                        pt=k;
                        b[pt]=a[j];
                        pt++;
                    }
                }
            }
        }
        for(int w=1;w<=n;w++)
        {
            for(int y=1;y<=m;y++)
            {
                if(b[w]==y)
                {
                    vis[y]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<vis[i]<<' ';
    }
    return 0;
}
