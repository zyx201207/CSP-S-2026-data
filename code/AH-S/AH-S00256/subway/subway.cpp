#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to,w;
};
int c,n,m,d,q,ans;
int w[100005],t[100005];
vector<edge>g[100005];
int st[100005],ed[100005];
void dfs(int u,int ed,int v,int step)
{
    if(u==ed)
    {
        ans=min(ans,v);
        return ;
    }
    if(step>m)return;
    for(auto t:g[u])
    {
        dfs(t.to,ed,v+w[u]+t.w,step+1);
    }
}
int main()
{
    freopen("subway1.in","r",stdin);
    freopen("subway1.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int u,v;
            cin>>u>>v;
            g[i].push_back({u,v});
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>st[i]>>ed[i];
        dfs(st[i],ed[i],0,1);
        cout<<ans<<'\n';
    }
    return 0;
}