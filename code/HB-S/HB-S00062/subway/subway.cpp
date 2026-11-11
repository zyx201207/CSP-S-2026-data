#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,k[505],dis[N],w[N],a[505][N],rd[N][505];
int t1[505][N],t[505][N];
int read()
{
    char c=getchar();int x=0,flag=1;
    while(c<'0'||c>'9'){if(c=='-'){flag=-1;}c=getchar();}
    while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}
    return x*flag;
}
void dij(int s)
{
    priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > >pq;
    memset(dis,0x3f,sizeof dis);
    pq.push({0,s});
    dis[s]=0;
    while(!pq.empty())
    {
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d>dis[u])
            continue;
        for(int i=1;i<=rd[u][0];i++)
        {
            int now=rd[u][i];
            for(int j=1;j<=k[now];j++)
            {
                int v=a[now][j];
                int w=t[now][j]+t1[now][u];
                if(dis[v]<dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }
    }
    return ;
}
int main()
{
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=n;i++)
    {
        k[i]=read();
        for(int j=1;j<=k[i];j++)
        {
            a[i][j]=read();
            t[i][j]=read();
            t1[i][a[i][j]]=t[i][j];
            rd[a[i][j]][++rd[a[i][j]][0]]=i;
        }
    }
    while(q--)
    {

        int x,y;
        x=read();y=read();
        dij(x);
        printf("%d\n",dis[y]+w[x]+w[y]);
    }
    return 0;
}
