#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],sum[500005],ans[300005];
vector<int>g[300005];

vector<int>edge[500005];

void dfs(int x,int f)
{
    sum[x]=1;
    for(auto y:edge[x])
    {
        if(y==f) continue;
        dfs(y,x);
        sum[x]+=sum[y];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        g[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=(int)g[i].size()-2;j++)
        {
            edge[g[i][j+1]].push_back(g[i][j]);
        }
        edge[g[i][g[i].size()-1]+1].push_back(g[i][g[i].size()-1]);
    }
    dfs(n,n+1);
    for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],sum[i]);
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}