#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct node
{
    int v,w;
};
vector<node>a[2500005],l;//a[i*n+j] : line i post j(zhantai)  a[j](zhanting)  a[i*n](super O post)
int dis[2500005];
/*void dijkstra(int st)
{
    dis[st]=0;
    for(auto [v,w]=a[st])
    {
        dis[v]=w;
    }
    for(int u=1;u<)
}*/
int minx=1000000005,st,ed;
bool vis[2500005];//l.size()
void dfs(int step,int len)
{
    if(step==ed)
    {
        minx=min(minx,len);
        return;
    }
    int z=a[step].size(),v,w;
    for(int i=0;i<z;++i)
    {
        v=a[step][i].v,w=a[step][i].w;
        if(!vis[v])
        {
            if(v%n!=0)vis[v]=1;
            dfs(v,len+w);
            vis[v]=0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)
        cin>>w[i];
    for(int i=1,k;i<=n;++i)
    {
        cin>>k;
        for(int j=1,x,y;j<=k;++j)
        {
            cin>>x>>y;
            a[i*n+x].push_back({i*n,0});
            a[i*n].push_back({i*n+x,0});
            a[x].push_back({i*n+x,y});
            a[i*n+x].push_back({x,y});
        }
    }
    while(q--)
    {
        minx=1000000005;
        cin>>st>>ed;
        vis[st]=1;
        dfs(st,0);
        cout<<minx+w[st]+w[ed]<<"\n";
    }
    fclose(stdin);
    //fclose(stdout);
    return 0;
}
