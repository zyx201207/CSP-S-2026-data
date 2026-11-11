#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v;
};
vector<node>v[100001];
int w[1000001],k[100001],dp[1000001],vis[100001],c[100001];
int minn = 1e9;
int cur = 0;
void dfs(int x,int y,int sum)
{
    if(x == y)
    {
        minn = min(sum,minn);
        return;
    }
    for(auto i:v[x])
    {
        if(vis[i.u] == 0)
        {
            vis[i.u] = 1;
            dfs(i.u,y,sum + i.v);
            vis[i.u] = 0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)cin>>w[i];
    for(int i = 1;i<=n;i++)
    {
        cin>>k[i];
        for(int j = 1;j<=k[i];j++)
        {
            int x,y;
            cin>>x>>y;
            v[i].push_back({x + n,y});
            v[x+n].push_back({i,y});
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        minn = 1e9;
        cur = 0;
        vis[l+n] = 1;
        dfs(l + n,r + n,0);
        cout<<minn + w[l] + w[r]<<endl;
    }
    return 0;
}
