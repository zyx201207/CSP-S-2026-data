#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,siz[1000005],dep[1000005],son[1000005],fa[1000005],top[1000005],fa[1000005];
bool chose[1000005]
vector<int> to[1000005];
void dfs1(int u,int f)
{
    dep[u]=dep[f]+1;
    fa[u]=f;
    siz[u]=1;
    for(int i=0;i<to[u].size();i++)
    {
        int v=to[u][i];
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v; 
    }
}
void dfs2(int u,int t)
{
    top[u]=t;
    if(son[u]) dfs2(son[u],t);
    for(int i=0;i<to[u].size();i++)
    {
        int v=to[u][i];
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[fa[top[u]]]<dep[fa[top[v]]]) swap(u,v);
        if(u==1) return u;
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) return u;
    return v;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        dfs1(1,0);
        dfs2(1,1);
        int minn=1e9;
        vector<pair<int,pair<int,int> > > minn;
        for(int i=1;i<=n;i++)
        {
            int maxx=-1,place=-1;
            for(int j=1;j<=n;j++)
            {
                if(dep[i]+dep[j]-2*dep[lca(i,j)]>maxx)
                {
                    maxx=dep[i]+dep[j]-2*dep[lca(i,j)];
                    place=j;
                }
            }
            minn.push_back({maxx,{i,place}});
        }
        sort(minn.begin(),minn.end());
        int cnt=0;
        for(int i=0;i<minn.size();i++)
        {
            if(!chosen[minn[i].second.first])
            {
                chosen[minn[i].second.first]=1;
                cnt++;
            }
            if(!chosen[minn[i].second.second])
            {
                chosen[minn[i].second.second]=1;
                cnt++;
            }
            if(cnt==5)
            {
                cout<<minn[i].first<<endl;
                break;
            }
        }
        memset(son[u],0,sizeof(son[u]));
        for(int i=1;i<=n;i++) to[i].clear();
        memset(chosen,0,sizeof(chosen));
    } 
    return 0;
}