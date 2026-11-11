#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull MAXLL=0x3FFFFFFFFFFFFFFFLL;
struct side
{
    bool operator<(const side& other)
    const{
        return dis>other.dis;
    }
    int id;
    ll dis;
}now;
vector<side>s[20503];
array<array<ll,2003>,2003>dis;
array<ll,20503>dis2;
array<ll,20003>w;
array<bool,20503>vis;
priority_queue<side>q;
ll c,n,m,d,qu;
void dij(int srt)
{
    vis.fill(0);
    now.id=srt;
    now.dis=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(vis[now.id])
        {
            continue;
        }
        vis[now.id]=1;
        for(side i:s[now.id])
        {
            side nxt;
            nxt.dis=now.dis+i.dis;
            nxt.id=i.id;
            if(nxt.dis<dis[srt][nxt.id])
            {
                dis[srt][nxt.id]=nxt.dis;
                q.push(nxt);
            }
        }
    }
    return;
}
void dij2(int srt)
{
    dis2.fill(MAXLL);//
    vis.fill(0);
    now.id=srt;
    now.dis=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(vis[now.id])
        {
            continue;
        }
        vis[now.id]=1;
        for(side i:s[now.id])
        {
            side nxt;
            nxt.dis=now.dis+i.dis;
            nxt.id=i.id;
            if(nxt.dis<dis2[nxt.id])
            {
                dis2[nxt.id]=nxt.dis;
                q.push(nxt);
            }
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>qu;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int a;ll t;
            cin>>a>>t;
            now.dis=t;now.id=a;
            s[m+i].push_back(now);
            now.id=m+i;
            s[a].push_back(now);
        }
    }
    if(c<=11)
    {
        for(int i=0;i<2002;i++)
        {
            dis[i].fill(MAXLL);
        }
        for(int i=0;i<qu;i++)
        {
            int u,v;
            cin>>u>>v;
            if(dis[u][v]==MAXLL)
            {
                dij(u);
            }
            cout<<dis[u][v]+w[u]+w[v]<<"\n";
        }
    }
    else
    {
        dis2.fill(MAXLL);
        for(int i=0;i<qu;i++)
        {
            int u,v;
            cin>>u>>v;
            dij2(u);
            cout<<dis2[v]+w[u]+w[v]<<"\n";
        }
    }
    return 0;
}
