#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=5e2+5,M=2e4+5;//N you wu!!!
struct node
{
    int v,w;//di w tiao xianlu
};
struct Node
{
    int x,y;//xianlu jiedian
};
vector<node>g[N];//g_0 zhanting
vector<int>e[N];//di i tiao xian lu jing guo j
vector<int>f[M];
int c,n,m,d,q;
int w[M],a[N][N],t[N][M];
int dep[N];
bool vis[N][M];
int bfs(int x,int y)
{
    queue<Node>Q;
    for(auto v:f[x])
        Q.push({v,x});
    while(!Q.empty())
    {
        Node tmp=Q.front();
        int u=tmp.y;
        int pre=tmp.x;
        Q.pop();
        if(vis[pre][y])
            return dep[pre];
        for(auto v:f[u])
        {
            if(dep[v])
                continue;
            for(auto i:e[v])
                Q.push({v,i});
            dep[v]=dep[pre]+1;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int minn=0x3f3f3f;
        for(int j=1;j<=k;j++)
        {
            int T;
            cin>>a[i][j]>>T;
            vis[i][a[i][j]]=1;
            t[i][a[i][j]]=T;
            minn=min(T,minn);
            e[i].push_back(a[i][j]);
            f[a[i][j]].push_back(i);
        }
        g[i].push_back({0,minn});
        g[0].push_back({i,minn});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int minn=0x3f3f3f3f;
            for(auto u:e[i])
            {
                for(auto v:e[j])
                {
                    if(u==v)
                    {
                        minn=min(minn,t[i][u]+t[j][v]);
                    }
                }
            }
            if(minn<0x3f3f3f3f)
            {
                g[i].push_back({j,minn});
                g[j].push_back({i,minn});
            }
        }
    }
    /*
    for(int i=0;i<=n;i++)
    {
        cout<<i<<":";
        for(auto x:g[i])
        {
            int v=x.v;
            int w=x.w;
            cout<<v<<" "<<w<<"|";
        }
        cout<<endl;
    }
    */
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<endl;
    }
    return 0;
}
