#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],f[1000010],p[1000010],vis[1000010],d=1;
int main()
{
    freopen("card.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]++;
        if(f[a[i]]>=2) d=i;
    }
    int op=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            vis[i]=0;
        }
        if(op==d)
        {
            d=i;
        }
        for(int j=d;j<=n;j++)
        {
            if(vis[a[j]]==0)
            {
                p[a[j]]++;
                vis[a[j]]=1;
            }

        }
        f[a[i]]--;
        op=d;
        for(int j=n;j>=i;j--)
        {
            if(f[a[j]]>=2)
            {
                d=j;
            }
        }

    }
    for(int i=1;i<=m;i++) cout<<p[i]<<" ";
    return 0;
}
