#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long b[300005];
int vis[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]]!=0)
            {
                for(int k=vis[a[j]];k<j;k++)
                {
                    vis[a[k]]=0;
                }
            }
            vis[a[j]]=j;
        }
        for(int j=1;j<=m;j++)
        {
            if(vis[j]!=0)
            {
                b[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<' ';
    }
    return 0;
}
