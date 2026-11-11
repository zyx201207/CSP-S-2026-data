#include<bits/stdc++.h>
using namespace std;
const int N=5e5+600;
struct node
{
    int to;
    int nxt;
    long long w;
}e[N*2];
long long s[N],dis[510][510];
int h[N],st[N],cnt=0;
int c,n,m,d,q;
long long read()
{
    long long sum=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    while (ch>='0'&&ch<='9') sum=sum*10+(ch-'0'),ch=getchar();
    return sum;
}
void write(long long num)
{
    if (num>9) write(num/10);
    putchar(num%10+'0');
}
void add(int u,int v,long long w)
{
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].nxt=h[u];
    h[u]=cnt++;
}
void dij(int u)
{
    for (int i=h[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].to;
        long long w1=e[i].w;
        for (int j=h[v];j!=-1;j=e[j].nxt)
        {
            int p=e[j].to;
            long long w2=e[j].w;
            if (u==p) continue;
            dis[u-m][p-m]=min(dis[u-m][p-m],w1+w2);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for (int i=1;i<=m;i++) s[i]=read();
    memset(h,-1,sizeof(h));
    for (int u=m+1;u<=m+n;u++)
    {
        int k;
        k=read();
        while (k--)
        {
            int v;
            long long w;
            v=read(),w=read();
            add(u,v,w);
            add(v,u,w);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for (int u=1;u<=n;u++) dis[u][u]=0,dij(u+m);
    for (int k=1;k<=n;k++)
    {
        for (int u=1;u<=n;u++)
        {
            for (int v=1;v<=n;v++)
            {
                dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
            }
        }
    }
    while (q--)
    {
        int x,y;
        x=read(),y=read();
        long long ans=1e18;
        for (int i=h[x];i!=-1;i=e[i].nxt)
        {
            int u=e[i].to;
            long long w1=e[i].w;
            for (int j=h[y];j!=-1;j=e[j].nxt)
            {
                int v=e[j].to;
                long long w2=e[j].w;
                ans=min(ans,s[x]+s[y]+w1+w2+dis[u-m][v-m]);
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}
