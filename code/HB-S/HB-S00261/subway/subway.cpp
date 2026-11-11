#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')f=0;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return f?x:-x;
}
int c,n,m,d,q,a[505050],k,pxy,csr,u,v,s,orz[505][505],ml=9e18;
struct sub{
    int r,p[21],t[21];
}b[505];
void floyd()
{
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(orz[i][k]<ml&&orz[k][j]<ml)
                    if(orz[i][j]>orz[i][k]+orz[k][j])orz[i][j]=orz[i][k]+orz[k][j];
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j)orz[i][j]=0;
            else orz[i][j]=ml;
        }
    for(int i=1;i<=m;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
        k=read();
        for(int j=1;j<=k;j++)
        {
            cin>>pxy>>csr;
            ++b[pxy].r;
            b[pxy].p[b[pxy].r]=i;
            b[pxy].t[b[pxy].r]=csr;
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<b[i].r;++j)
            for(int k=j+1;k<=b[i].r;++k)
                orz[b[i].p[j]][b[i].p[k]]=orz[b[i].p[k]][b[i].p[j]]=min(orz[b[i].p[j]][b[i].p[k]],b[i].t[j]+b[i].t[k]);
    }
    floyd();
    while(q--)
    {
        cin>>u>>v;
        s=ml;
        for(int i=1;i<=b[u].r;++i)
            for(int j=1;j<=b[v].r;++j)
                s=min(s,b[u].t[i]+b[v].t[j]+orz[min(b[u].p[i],b[v].p[j])][max(b[u].p[i],b[v].p[j])]);
        cout<<s+a[u]+a[v]<<endl;
    }
}
