#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
vector<int> v[N];
vector<int> lx[N];
vector<int> bian[N];
int w[N];
int k[N];
int t[507][N];
int x,y;
int dis[N];
bool vis[N];
int T;
bool vvvvv=0;
void bfs(int root)
{
    for(int i : bian[root])
    {
        for(int j : v[i])
        {
            if(vis[i])
                continue;
            vis[i]=1;
            dis[j]=min(dis[j],dis[i]+2*T);
            bfs(j);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=2*k[i]-1;j++)
        {
            int a,ti;
            cin>>a>>ti;
            v[i].push_back(a);
            t[i][a]=ti;
            T=ti;
            //cout<<"ti:"<<ti<<'\n';
            bian[a].push_back(i);
        }
    }
    while(q--)
    {
        memset(dis,0x3f,sizeof(dis));
        vvvvv=0;
        memset(vis,0,sizeof(vis));
        cin>>x>>y;
        //cout<<T<<'\n';
        int ans=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
