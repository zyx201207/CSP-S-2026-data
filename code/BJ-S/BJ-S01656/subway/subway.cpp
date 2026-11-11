#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v;
    long long w;
};
vector<node> a[100005];
struct nod{
    int u;
    long long w;
    bool friend operator < (const nod A,const nod B)
    {
        return A.w>B.w;
    }
};
long long dis[100005];
int vis[100005];
long long w[100005],aa[100005],t[100005];
void dij(int s)
{
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    priority_queue<nod> q;
    q.push({s,0});
    dis[s]=0;
    while(q.size())
    {
        int u=q.top().u;
        q.pop();
        if(vis[u]==1) continue;
        vis[u]=1;
        for(auto x:a[u])
        {
            int v=x.v;
            long long w=x.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int _=1;_<=n;_++)
    {
        int o;
        cin>>o;
        for(int i=1;i<=o;i++) cin>>aa[i]>>t[i];
        for(int i=1;i<=o;i++)
        {
            for(int j=i+1;j<=o;j++)
            {
                a[aa[i]].push_back({aa[j],t[i]+t[j]});
                a[aa[j]].push_back({aa[i],t[i]+t[j]});
           //     cout<<aa[i]<<" "<<aa[j]<<" "<<t[i]+t[j]<<"\n";
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        dij(x);
        cout<<w[x]+w[y]+dis[y]<<"\n";
    }
    return 0;
}
