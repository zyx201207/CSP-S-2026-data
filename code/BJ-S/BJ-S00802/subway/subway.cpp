#include<bits/stdc++.h>
using namespace std;
int stt,fin,c,n,m,d,q,w[305],k[305],sk[305][305][305],vis[505][505],a[505][505],t[505][505];
int g[505][500005];
int ans=2e9;
void dfs(int x,int y,int sum)
{
    if(x==0&&y==fin)
    {
        ans=min(ans,sum);
        return;
    }
    if(x==0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(sk[y][i][j]&&!vis[i][j])
                {
                    vis[i][j]=1;
                    dfs(i,j,sum+t[i][j]);
                    vis[i][j]=0;
                }
            }
        }
    }
    else
    {
        if(vis[0][a[x][y]]==0)
        {
            vis[0][a[x][y]]=1;
            dfs(0,a[x][y],sum+t[x][y]);
            vis[0][a[x][y]]=0;
        }
        for(int i=1;i<=k[x];i++)
        {
            if(vis[x][i])continue;
            vis[x][i]=1;
            dfs(x,i,sum);
            vis[x][i]=0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    int flag;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            if(i==1&&j==1)flag=t[i][j];
            if(t[i][j]!=flag)flag=-1;
            sk[a[i][j]][i][j]=1;
        }
    }
    if(n==1||flag==0)
    {
        for(int i=1;i<=q;i++)
        {
            cin>>stt>>fin;
            cout<<w[stt]+w[fin]<<endl;
        }
    }
    else
    {
        for(int i=1;i<=q;i++)
        {
            cin>>stt>>fin;
            ans=2e9;
            dfs(0,stt,0);
            cout<<w[stt]+ans+w[fin]<<endl;
        }
    }
    return 0;
}