#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f;
unordered_map<int,vector<int>> um;
vector<vector<pair<int,pair<int,int>>>> t;
vector<vector<int>> graph,g,h;
vector<int> a,dis,vis,l;
int n,m,d,q;
void solve()
{
    cin>>n>>m>>d>>q;
    a.resize(1e6+1);
    t.resize(1e6+1);
    l.resize(1e6+1);
    g.resize(1e6+1);
    h.resize(1e6+1);
    dis.resize(1e6+1);
    vis.resize(1e6+1);
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>l[i];
        g[i].resize(l[i]+1);
        h[i].resize(l[i]+1);
        for (int j=1;j<=l[i];j++)
        {
            int x,y;
            cin>>x>>y;
            g[i][j]=x;
            h[i][j]=y;
            t[x].push_back({i,{j,y}});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        if (um.count(x))
        {
            cout<<um[x][y]+a[x]+a[y]<<'\n';
            continue;
        }
        if (um.count(y))
        {
            cout<<um[y][x]+a[x]+a[y]<<'\n';
            continue;
        }
        fill(dis.begin()+1,dis.end(),inf);
        fill(vis.begin()+1,vis.end(),0);
        dis[x]=0;
        pq.push({0,x});
        while (!pq.empty())
        {
            int cur=pq.top().second;
            pq.pop();
            if (vis[cur])
            {
                continue;
            }
            vis[cur]=true;
            for (pair<int,pair<int,int>> i:t[cur])
            {
                for (int j=1;j<=l[i.first];j++)
                {
                    int v=g[i.first][j],w=i.second.second+h[i.first][j];
                    if (dis[v]>dis[cur]+w)
                    {
                        dis[v]=dis[cur]+w;
                        pq.push({dis[v],v});
                    }
                }
            }
        }
        cout<<dis[y]+a[x]+a[y]<<'\n';
        swap(um[x],dis);
    }
    return;
}
signed main()
{
    // freopen("subway/subway2.in","r",stdin);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case,TestCase=1;
    cin>>Case;
    // cin>>TestCase;
    for (int CaseId=1;CaseId<=TestCase;CaseId++)
    {
        solve();
    }
    return 0;
}

/*
g++ subway.cpp -o subwayy -std=c++14 -O2
./subwayy
*/