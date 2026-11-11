#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
const int maxp=1e4+5;
int c,n,m,d,Q;
struct node
{
    int v,w;
};
int ans[maxn];
bool vis[maxn];
vector<node> g[maxn];
int dfs(int s,int e)
{
    if(s==e)return 0;
    vis[s]=1;
    int ans=1e9;
    for(int i=0; i<g[s].size(); i++)
    {
        if(vis[g[s][i].v]==0)
            ans=min(ans,dfs(g[s][i].v,e)+g[s][i].w);
    }
    vis[s]=0;
    return ans;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1; i<=m; i++)
    {
        int x;
        cin>>x;
        g[i].push_back(node{m+i,x});
        g[m+i].push_back(node{i,x});
    }
    for(int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        for(int j=1; j<=k; j++)
        {
            int a,t;
            cin>>a>>t;
            g[m+a].push_back(node{2*m+i,t});
            g[2*m+i].push_back(node{m+a,t});
        }
    }
    for(int i=1; i<=Q; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<dfs(x,y)<<endl;
    }
    return 0;
}
