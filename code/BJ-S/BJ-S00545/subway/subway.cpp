#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
int dis[N][N];
int w[M];
int k[N];
int vis[N];
int c,n,m,d,q;
vector<int> a[N];
struct node
{
    int vto;
    int val;
};
struct node2
{
    int time;
    int id;
};
vector<node> g[N];
vector<node2> t[M];
void add_Edge(int u,int v,int Edge_v)
{
    node temp;
    temp.vto = v;
    temp.val = Edge_v;
    g[u].push_back(temp);
    return;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];

    }
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            int t1,t2;
            cin >> t1 >> t2; // t1 : id , t2 : time
            a[i].push_back(t1);
            node2 temp;
            temp.id = i;
            temp.time = t2;
            t[t1].push_back(temp);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < a[i].size();j++)
        {
            int k2 = a[i][j];
            int edge_v = 0;
            if(t[k2].size() >= 2)
            {
                for(auto to : t[k2])
                {
                    if(to.id == i) edge_v = to.time;
                }
                for(auto to : t[k2])
                {
                    if(to.id == i) continue;
                    add_Edge(i,to.id,edge_v + to.time);
                }
            }
        }
    }
    /*for(int i = 1;i <= n;i++)
    {
        for(auto k : g[i]) cout << k.vto << " " << k.val <<" ";
        cout << '\n';
    }*/
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dis[i][j] = 1e18;
            vis[j] = 0;
        }
        dis[i][i] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(dis[i][i],i));
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto E : g[u])
            {
                int v = E.vto;
                if(dis[i][v] > dis[i][u] + E.val)
                {
                    dis[i][v] = dis[i][u] + E.val;
                    if(!vis[v]) pq.push(make_pair(dis[i][v],v));
                }
            }
        }
    }
    for(int i = 1;i <= q;i++)
    {
        int x,y;
        cin >> x >> y;
        int ans = 1e18;
        for(auto temp : t[x])
        {
            for(auto temp2 : t[y])
            {
                int id1 = temp.id;
                int id2 = temp2.id;
                ans = min(ans,dis[id1][id2] + temp.time + temp2.time);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
