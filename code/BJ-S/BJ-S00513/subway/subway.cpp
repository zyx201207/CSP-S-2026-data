#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10005],k[505],a[505][305],t[505][305],g[10005][10005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(g,0,sizeof(g));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k[i];j++)
        {
            for(int kk=j+1;kk<=k[i];kk++)
            {
                if(g[a[i][j]][a[i][kk]]) g[a[i][j]][a[i][kk]]=min(t[i][j]+t[i][kk],g[a[i][j]][a[i][kk]]);
                else g[a[i][j]][a[i][kk]]=t[i][j]+t[i][kk];
                g[a[i][kk]][a[i][j]]=g[a[i][j]][a[i][kk]];
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(g[i][k]==0||g[k][j]==0) continue;
                if(g[i][j]) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                else g[i][j]=g[i][k]+g[k][j];
                g[j][i]=g[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<g[x][y]+w[x]+w[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

