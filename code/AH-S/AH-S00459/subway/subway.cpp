#include<bits/stdc++.h>

using namespace std;
long long read()
{
char ch;
long long w=1,s=0;
ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') w=-1;
    ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
    s=s*10+ch-'0';
    ch=getchar();
    }
return w*s;
}
struct node
{
int p;
long long w;
};
int c,n,m,d,q,k;
long long w1[500005],w2[505][505],dis[505][505],ans;
priority_queue<double,vector<double>,greater<double>> h;
vector<node> a[500005];
vector<int> e[505];
void dijkstra(int s)
{
double x;
int to;
    for(int i:e[s])
    {
    dis[s][i]=w2[i][s];
    h.push(dis[s][i]+i*0.001);
    }
    while(!h.empty())
    {
    x=h.top();
    h.pop();
    to=(long long)(x*(long long)(1000))%1000;
        for(int i:e[to])
        {
            if(dis[s][i]<=dis[s][to]+w2[to][i]) continue;
        dis[s][i]=dis[s][to]+w2[to][i];
        h.push(dis[s][i]+i*0.001);
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(w2,1e9+10,sizeof(w2));
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++)
    {
    w1[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
    k=read();
        for(int x,y,j=1;j<=k;j++)
        {
        x=read();
        y=read();
            for(node t:a[x])
            {
            w2[t.p][i]=min(w2[t.p][i],t.w+y);
            w2[i][t.p]=w2[t.p][i];
            }
        a[x].push_back((node){i,y});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(w2[i][j]==1e9+10) continue;
        e[i].push_back(j);
        e[j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
    dijkstra(i);
    }
    for(int x,y,i=1;i<=q;i++)
    {
    x=read();
    y=read();
    ans=-1;
        for(node t1:a[x])
        {
            for(node t2:a[y])
            {
                if(ans==-1) ans=w1[x]+w1[y]+t1.w+t2.w+dis[t1.p][t2.p];
                else ans=min(ans,w1[x]+w1[y]+t1.w+t2.w+dis[t1.p][t2.p]);
            }
        }
    cout<<ans<<endl;
    }
    return 0;
}
