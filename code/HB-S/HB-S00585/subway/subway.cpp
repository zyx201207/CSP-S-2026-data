#include<bits/stdc++.h>
using namespace std;
const int M=501005;
long long W[M],dis[505][505],len[M][21];
struct edge
{
    int to,nxt;
    long long val;
}e[M*2];
int nd,pos[M][21],cnt[M];
long long read()
{
    long long x=0,fu=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            fu=-fu;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*fu;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,l,r,u,v,k;
    long long ans,w;
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)
        W[i]=read();
    for(int i=1;i<=n;i++)
    {
        nd++;
        k=read();
        for(int j=1;j<=k;j++)
        {
            v=read();w=read();
            pos[v][++cnt[v]]=nd;
            len[v][cnt[v]]=w;
        }
    }
    for(int i=1;i<=nd;i++)
        for(int j=1;j<=nd;j++)
            if(i!=j)
                dis[i][j]=1e18;
    for(int i=1;i<=m;i++)
        for(int x=1;x<=cnt[i];x++)
            for(int y=x+1;y<=cnt[i];y++)
            {
                u=pos[i][x],v=pos[i][y];
                dis[u][v]=min(dis[u][v],len[i][x]+len[i][y]);
                dis[v][u]=dis[u][v];
            }
    for(int md=1;md<=nd;md++)
        for(int x=1;x<=nd;x++)
            for(int y=1;y<=nd;y++)
            {
                dis[x][y]=min(dis[x][y],dis[x][md]+dis[md][y]);
            }
    for(int i=1;i<=q;i++)
    {
        l=read();r=read();
        ans=1e18;
        for(int x=1;x<=cnt[l];x++)
            for(int y=1;y<=cnt[r];y++)
            {
                u=pos[l][x];
                v=pos[r][y];
                ans=min(ans,W[l]+len[l][x]+dis[u][v]+len[r][y]+W[r]);
            }
        cout<<ans<<"\n";
    }
    return 0;
}