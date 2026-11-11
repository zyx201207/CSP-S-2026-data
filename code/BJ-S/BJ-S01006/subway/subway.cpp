#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXM = 500005;
const ll inf = 2147483647;

struct edge
{
    int e;
    int t;
    int next;
};

edge eg[MAXM * 4];
int head[MAXM * 4];
int cnt = 0;

inline void add(int s,int e,int t)
{
    eg[cnt].e = e;
    eg[cnt].t = t;
    eg[cnt].next = head[s];
    head[s] = cnt++;

    eg[cnt].e = s;
    eg[cnt].t = t;
    eg[cnt].next = head[e];
    head[e] = cnt++;
    return;
}

int c,n,m,d,Q;
int w[MAXM];
int cot;
ll dis[MAXM * 4];
bool vis[MAXM * 4];

priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;

inline void dijkstra(int s)
{
    while(!q.empty())
    {
        q.pop();
    }
    for(int i = 1;i <= cot;i++)
    {
        dis[i] = inf * inf;
        vis[i] = 0;
    }
    dis[s] = 0;
    q.push(make_pair(s,0));
    while(!q.empty())
    {
        int x = q.top().first;
        int di = q.top().second;
        q.pop();
        if(vis[x] || di > dis[x])
        {
            continue;
        }
        vis[x] = 1;
        for(int i = head[x];i != -1;i = eg[i].next)
        {
            if(dis[x] + eg[i].t < dis[eg[i].e])
            {
                dis[eg[i].e] = dis[x] + eg[i].t;
                q.push(make_pair(eg[i].e,dis[eg[i].e]));
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(head,-1,sizeof(head));
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    cot = m;
    for(int i = 1;i <= n;i++)
    {
        int k,a1,t1,a,t;
        cin >> k >> a1 >> t1;
        cot++;
        add(cot,a1,t1);
        int cot1 = cot;
        for(int j = 2;j <= k;j++)
        {
            cin >> a >> t;
            cot++;
            add(cot1,cot,0);
            add(cot,a,t);
        }
    }
    while(Q--)
    {
        int x,y;
        cin >> x >> y;
        dijkstra(x);
        cout << w[x] + dis[y] + w[y] << '\n';
    }

    return 0;
}
