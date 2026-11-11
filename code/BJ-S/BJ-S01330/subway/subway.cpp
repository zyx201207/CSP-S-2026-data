#include<bits/stdc++.h>
using namespace std;
int c,n,m,d1,q;
const int MAXM=5e5+5e2+8;
const int INF=0x3f3f3f3f;
int w[MAXM];
int d[MAXM];
bool in[MAXM];
struct node{
    int v,w;
};
vector<node>g[MAXM];
void z(int x)
{
    queue<int>q;
    q.push(x);
    d[x]=0;
    in[x]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),in[u]=0;
        for(auto [v,w]:g[u])
        {
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                if(!in[v])q.push(v),in[v]=1;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d1>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            g[i+500000].push_back({a,t}),g[a].push_back({i+500000,t});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        memset(d,INF,sizeof(d));
        z(x);
        cout<<w[x]+w[y]+d[y]<<"\n";
    }
}
