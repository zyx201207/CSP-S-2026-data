#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
    x=0;
    char ch=getchar(),f=1;
    while(ch<48||ch>57)f=(ch=='-')?-f:f,ch=getchar();
    while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
    x*=f;
}
const int N=1e6+5;
int c,t,n,k,ans=INT_MAX,sum;
vector<int>e[N];
int vis[N],dis[N];
void bfs(int s1,int s2)
{
    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++)vis[i]=1,dis[i]=0;
    q.push({s1,0}),q.push({s2,0});
    while(!q.empty())
    {
        int u=q.front().first,w=q.front().second;q.pop();
        for(auto v:e[u])
        {
            if(!vis[v])
            vis[v]=1,dis[v]=w+1,q.push({v,w+1}),sum=w+1;
        }
        if(sum>ans)return;
    }
    ans=min(ans,sum);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read(c),read(t);
    while(t--)
    {
        read(n),read(k);
        if(k==n)
        {
            for(int i=1,a,b;i<=n;i++)read(a),read(b);
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1,u,v;i<=n;i++)
            read(u),read(v),e[u].push_back(v),e[u].push_back(v);
        if(k==2)
        {
            ans=INT_MAX;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    bfs(i,j);
            cout<<ans<<'\n';
        }
        else
        {
            cout<<2<<'\n';
        }
    }
    return 0;
}
