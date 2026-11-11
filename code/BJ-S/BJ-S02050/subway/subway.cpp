#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[505];
struct node
{
    int nx,sum;
    bool operator<(const node& other)const&
    {
        return sum>other.sum;
    }
};
struct code
{
    int now,sum,fa;
    bool operator<(const code& other)const&
    {
        return sum>other.sum;
    }
};
vector<node>b[500505];
priority_queue<code>s;
int dij(int x,int y)
{
    int k[505];
    bool flag[50505];
    for(int i=1;i<=n;i++)
    {
        if(i!=x)k[i]=1e9;
    }
    s.push({x,0,0});
    while(!s.empty())
    {
        int u=s.top().now,e=s.top().sum,father=s.top().fa;
        if(e>=k[u])
        {
            s.pop();
            continue;
        }
        for(int i=0;i<=b[u].size();i++)
        {
            if(b[u][i].nx==father)continue;
            if(b[u][i].sum+k[u]<k[b[u][i].nx])
            {
                k[b[u][i].nx]=b[u][i].sum+k[u];
                s.push({b[u][i].nx,k[b[u][i].nx],u});
            }
        }
    }
    return k[y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int e,f;
            cin>>e>>f;
            b[i+n].push_back({e,f});
            b[e].push_back({i+n,f});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<dij(x,y)+a[x]+a[y]<<endl;
    }
    return 0;
}
