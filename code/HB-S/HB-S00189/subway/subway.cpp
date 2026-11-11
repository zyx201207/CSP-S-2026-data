#include<bits/stdc++.h>
using namespace std;
long long w[500005],k[505];
bool vis[500005],viss[505];
vector<int> a[500005];
vector<int> t[500005];
vector<int> zh[500005];
vector<int> zt[500005];
long long ans=INT_MAX;
long long dfs(int sta,int la,long long time)
{
    if(sta==la)
    {
        ans=min(ans,time);
        return ans;
    }
    for(int i=0;i<zh[sta].size();i++)
    {
        if(viss[zh[sta][zh[sta][i]]]) continue;
        viss[zh[sta][zh[sta][i]]]=1;
        for(int j=0;j<a[zh[sta][i]].size();j++)
        {
            if(a[zh[sta][i]][j]==sta||vis[a[zh[sta][i]][j]]) continue;
            vis[a[zh[sta][i]][j]]=1;
            dfs(a[zh[sta][i]][j],la,time+zt[sta][zh[sta][i]]+zt[a[zh[sta][i]][j]][zh[sta][i]]);
            vis[a[zh[sta][i]][j]]=0;
        }
        viss[zh[sta][zh[sta][i]]]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            long long aa,tt;
            cin>>aa>>tt;
            a[i].push_back(aa);
            t[i].push_back(tt);
            zh[aa].push_back(i);
            zt[aa].push_back(tt);
        }
    }
    for(int i=1;i<=q;i++)
    {
        memset(vis,0,sizeof(vis));
        long long u,v;
        cin>>u>>v;
        vis[u]=1;
        vis[v]=1;
        ans=INT_MAX;
        cout<<dfs(u,v,w[v]+w[u])<<'\n';
    }
    return 0;
}
