#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
struct node
{
    int u;
    int w;
}way[205][405];
int k[205];
int v[500005][25];
int pos[500005];
int ans;
int s,e;
void dfs(int x,int sum)
{
    if(x==e)
    {
        ans=min(ans,sum);
        return;
    }
    for(int i=1;i<=pos[x];i++)
    {
        int now=v[x][i];
        int txx;
        for(int j=1;j<=k[now];j++)
        {
            if(way[now][j].u==x)
            {
                txx=way[now][j].w;
            }
        }
        for(int j=1;j<=k[now];j++)
        {
            if(way[now][j].u!=x)
            {
                dfs(way[now][j].u,sum+txx+way[now][j].w);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int dismeaningful;
    cin>>dismeaningful;
    cin>>n>>m;
    int d,q;
    cin>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>way[i][j].u>>way[i][j].w;
            v[way[i][j].u][++pos[way[i][j].u]]=i;
        }
    }
    while(q--)
    {
        ans=1e9;
        cin>>s>>e;
        dfs(s,a[s]+a[e]);
        cout<<ans<<endl;
    }
    return 0;
}
