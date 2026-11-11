#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int fa[N][20];
int de[N];
vector<int> G[N];
int maxn=-1;
int maxw;
int maf;
void dfs(int u,int father,int dep)
{
    if(dep>maxn)
    {
        maxn=dep;
        maxw=u;
        maf=father;
    }
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u,dep+1);
    }
}
int f=1;
int midd;
void dfs2(int u,int father,int dep)
{
    if(dep==maxn/2||f==0)
    {
        midd=u;
        f=0;
        return;
    }
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u,dep+1);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,k,u,v;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(n==k)
        {
            cout<<0<<endl;
            continue;
        }
        dfs(1,0,0);
        dfs(maxw,maf,0);
        maxn+=1;
        if(k==1)
        {
            cout<<maxn-(maxn/2)<<endl;
        }
        else
        {
            cout<<(maxn-k)/4+1<<endl;
        }

    }
    return 0;
}
