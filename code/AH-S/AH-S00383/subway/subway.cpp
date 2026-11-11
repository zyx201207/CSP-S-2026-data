#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,Q;
bool vis[1000005];
long long W[500005],dis[1000005];
long long read()
{
    long long x = 0;
    char ch = getchar();
    while('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
struct Edge
{
    int v;
    long long w;
};
vector<Edge> e[1000005];
struct Point
{
    int p;
    long long w;
};
struct cmp
{
    bool operator()(Point &a,Point &b)
    {
        return a.w > b.w;
    }
};
priority_queue<Point,vector<Point>,cmp> q;
void dijsktra(int s)
{
    for(int i = 1; i <= (n + 1) * m; i++)
    {
        vis[i] = false;
        dis[i] = 0x3f3f3f3f3f3f3f3f;
    }
    dis[s] = 0;
    q.push((Point){s,0});
    while(!q.empty())
    {
        Point head = q.top();
        q.pop();
        while(vis[head.p] && !q.empty())
        {
            head = q.top();
            q.pop();
        }
        if(vis[head.p]) break;
        int now = head.p;
        vis[now] = true;
        for(int i = 0; i < e[now].size(); i++)
        {
            int v = e[now][i].v;
            long long w = e[now][i].w;
            if(dis[v] >= dis[now] + w)
            {
                dis[v] = dis[now] + w;
                q.push((Point){v,dis[v]});
            }
        }
    }
}
struct STU
{
    int U,V,id;
    long long ans;
}ask[100005];
bool cmp1(STU x,STU y)
{
    return x.U < y.U;
}
bool cmp2(STU x,STU y)
{
    return x.id < y.id;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    c = read();
    n = read();
    m = read();
    d = read();
    Q = read();
    for(int i = 1; i <= m; i++)
        W[i] = read();
    for(int line = 1; line <= n; line++)
    {
        int num;
        num = read();
        vector<int> id;
        for(int i = 1; i <= num; i++)
        {
            int v;
            long long w;
            v = read();
            w = read();
            id.push_back(v + line * m);
            e[v].push_back((Edge){v + line * m,w});
            e[v + line * m].push_back((Edge){v,w});
        }
        for(int i = 1; i < id.size(); i++)
        {
            e[id[i]].push_back((Edge){id[i - 1],0});
            e[id[i - 1]].push_back((Edge){id[i],0});
        }
    }
    for(int i = 1; i <= Q; i++)
    {
        ask[i].U = read();
        ask[i].V = read();
        ask[i].id = i;
    }
    sort(ask + 1,ask + Q + 1,cmp1);
    for(int i = 1; i <= Q; i++)
    {
        if(ask[i].U != ask[i - 1].U)
            dijsktra(ask[i].U);
        ask[i].ans = dis[ask[i].V] + W[ask[i].U] + W[ask[i].V];
    }
    sort(ask + 1,ask + Q + 1,cmp2);
    for(int i = 1; i <= Q; i++)
        cout << ask[i].ans << "\n";
    return 0;
}
