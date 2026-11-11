#include <bits/stdc++.h>
#define int long long
#define N 500005

using namespace std;

int c,n,m,d,q,w[N],k[505],x,y,a1,t1,a2,t2,ans,vis[N];
struct edge
{
    int v,val;
};
vector<edge>v[N];
void dfs(int now,int res)
{
    if(now==y)ans=min(ans,res);
    vis[now]=1;
    for(int i=0;i<v[now].size();i++)
        dfs(v[now][i].v,res+v[now][i].val);
    vis[now]=0;
}
void solve()
{
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i]>>a1>>t1>>a2>>t2;
        v[a1].push_back((edge){a2,t1+t2});
        v[a2].push_back((edge){a1,t1+t2});
    }
    while(q--)
    {
        cin>>x>>y;
        dfs(x,0);
        cout<<w[x]+w[y]+ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(7<=c&&c<=11)
        solve();
    return 0;
}
