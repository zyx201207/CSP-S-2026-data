#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=501,M=5e5+1;
int c,n,m,d,q;
int w[M];
vector<int> a[N],t[N];
int k[N];
int read()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
    return x*w;
}
void write(ll x)
{
    if(x<0) putchar('-'),x*=-1;
    if(x>=10) write(x/10);
    putchar(x%10+'0');
    return ;
}
struct edge
{
    int to,nxt,w;
}e[20*M*2];
int h[M+N],tot=0;
void build(int u,int v,int w)
{
    e[++tot].to=v;
    e[tot].nxt=h[u];
    e[tot].w=w;
    h[u]=tot;
}
// ll dis[N][500000];
// ll dd[N][M];
struct node
{
    int u;
    ll dis;
    bool operator < (const node &x) const
    {
        return dis>x.dis;
    }
};
int vis[M+N];
// void dij(int s,ll *dis[])
// {
//     memset(vis,0,sizeof(vis));
//     priority_queue<node> que;
//     for(int i=1;i<=m+n;i++) dis[s][i]=2e18;
//     dis[s][s]=0;
//     que.push((node){s,0});
//     while(que.size())
//     {
//         node tmp=que.top();
//         // cout<<tmp.u<<endl;
//         que.pop();
//         int u=tmp.u;
//         if(tmp.dis>dis[s][u]) continue;
//         for(int i=h[u];i;i=e[i].nxt)
//         {
//             int v=e[i].to,w=e[i].w;
//             if(dis[s][u]+w<dis[s][v])
//             {
//                 dis[s][v]=dis[s][u]+w;
//                 que.push((node){v,dis[s][v]});
//             }
//         }
//     }
// }
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++)
    {
        k[i]=read();
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=k[i];j++)
        {
            int aa=read(),tt=read();
            a[i].push_back(aa);
            t[i].push_back(tt);
        }
    }
    // if(c<=11)
    // {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                int v=a[i][j],w=t[i][j];
                build(m+i,v,w);
                build(v,m+i,w);
            }
        }
        ll dis[n+1][n+m+1];
        for(int kk=1;kk<=n;kk++)
        {
            // dij(m+i,dis);
            int s=m+kk;
            memset(vis,0,sizeof(vis));
            priority_queue<node> que;
            for(int i=1;i<=m+n;i++) dis[s-m][i]=2e18;
            dis[s-m][s]=0;
            que.push((node){s,0});
            while(que.size())
            {
                node tmp=que.top();
                // cout<<tmp.u<<endl;
                que.pop();
                int u=tmp.u;
                if(tmp.dis>dis[s-m][u]) continue;
                for(int i=h[u];i;i=e[i].nxt)
                {
                    int v=e[i].to,w=e[i].w;
                    if(dis[s-m][u]+w<dis[s-m][v])
                    {
                        dis[s-m][v]=dis[s-m][u]+w;
                        que.push((node){v,dis[s-m][v]});
                    }
                }
            }
        }
        while(q--)
        {
            int x=read(),y=read();
            ll ans=2e18;
            for(int i=h[x];i;i=e[i].nxt)
            {
                int v=e[i].to;
                // cout<<v<<endl;
                ans=min(ans,dis[v-m][x]+dis[v-m][y]);
            }
            ans=ans+w[x]+w[y];
            write(ans);
            putchar('\n');
        }
        return 0;
    // }
    return 0;
}