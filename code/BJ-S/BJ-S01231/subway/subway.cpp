#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int M=505;
int a[N];
bool vis[M];
int P[M][M];
int dis[M][M];
vector<pair<int,int>> p[N];
vector<pair<int,int>> G[M];
void dijkstra(int s)
{
    memset(vis,0,sizeof vis);
    dis[s][s]=0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        auto x=q.top();
        q.pop();
        if(vis[x.second]) continue;
        vis[x.second]=true;
        for(auto v:G[x.second])
        {
            if(!vis[v.first]&&dis[s][v.first]>dis[s][x.second]+v.second)
            {
                dis[s][v.first]=dis[s][x.second]+v.second;
                q.push(make_pair(-dis[s][v.first],v.first));
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,t;
            cin>>x>>t;
            p[x].push_back(make_pair(i,t));
        }
    }
    memset(P,0x3f,sizeof P);
    for(int i=1;i<=m;i++)
    {
        for(auto x:p[i])
        {
            for(auto y:p[i])
            {
                if(x==y) continue;
                P[x.first][y.first]=min(P[x.first][y.first],x.second+y.second);
                P[y.first][x.first]=min(P[y.first][x.first],x.second+y.second);
                //cout<<x.first<<" "<<y.first<<endl;
                //G[x.first].push_back(make_pair(y.first,x.second+y.second));
                //G[y.first].push_back(make_pair(x.first,x.second+y.second));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j||P[i][j]==0x3f3f3f3f3f3f3f3f) continue;
            //cout<<i<<" "<<j<<" "<<P[i][j]<<endl;
            G[i].push_back(make_pair(j,P[i][j]));
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dijkstra(i);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int ans=LONG_LONG_MAX;
        for(auto x:p[l])
        {
            for(auto y:p[r])
            {
                //cout<<x.first<<" "<<y.first<<" "<<dis[x.first][y.first]<<endl;
                ans=min(ans,x.second+y.second+dis[x.first][y.first]);
            }
        }
        cout<<ans+a[l]+a[r]<<endl;
    }
    return 0;
}
