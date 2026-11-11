#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
typedef pair<int,int> pii;

int c,n,m,d,q,w[N];
vector<pii> G[N];
int dis[N][N];
void dij(int s)
{
    dis[s][s]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,s});
    while (!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        int w=a.first,v=a.second;
        if (w>dis[s][v]) continue;
        for (auto e:G[v])
        {
            int b=e.first,c=e.second;
            if (dis[s][c]>b+dis[s][v])
            {
                dis[s][c]=b+dis[s][v];
                pq.push({dis[s][c],c});
            }
        }
    }
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    for (int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int a[k+5],t[k+5];
        for (int j=1;j<=k;j++)
        {
            cin>>a[j]>>t[j];
        }
        for (int j=1;j<k;j++)
        {
            for (int o=j+1;o<=k;o++)
            {
                G[a[j]].push_back({t[j]+t[o],a[o]});
                G[a[o]].push_back({t[j]+t[o],a[j]});
            }
            
        }
    }
    for (int i=1;i<=m;i++)
    {
        dij(i);
    }
    for (int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dis[x][y]<<'\n';
    }
    
    return 0;
}