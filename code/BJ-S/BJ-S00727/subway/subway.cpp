#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
    int vv,xian;
};

struct node
{
    int x,y,hao;
};

struct Nodee
{
    int dian;
    int dis;
    int xian;
    bool operator < (const Nodee &x)const{return x.dis<dis;}
};

priority_queue <Nodee> q;

map <pair<int,int>,int> mp;

vector <int> xianlu[500005];

vector <Node> e[500005];

int w[500005];
int a[500005];
int dis[20005][505];
int print[500005];
node shuru[500005];
bool vis[500005];
int c,n,m,d,qq;

bool cmp(node x,node y)
{
    return x.x<y.x;
}

void Dijkstra(int x)
{
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            dis[i][j]=4e18;
    for (int i=0;i<xianlu[x].size();i++)
    {
        dis[x][xianlu[x][i]]=w[x]+mp[make_pair(x,xianlu[x][i])];
        q.push({x,w[x]+mp[make_pair(x,xianlu[x][i])],xianlu[x][i]});
    }
    while (!q.empty())
    {
        Nodee f=q.top();
        q.pop();
        //cout << "&&&" << f.dian << " " << f.xian << " " << f.dis << endl;
        if (dis[f.dian][f.xian]!=f.dis) continue;
        for (int i=0;i<e[f.dian].size();i++)
        {
            int shu=f.dis+(e[f.dian][i].xian!=f.xian?mp[make_pair(f.dian,f.xian)]+mp[make_pair(f.dian,e[f.dian][i].xian)]:0);
            if (shu<dis[e[f.dian][i].vv][e[f.dian][i].xian])
            {
                dis[e[f.dian][i].vv][e[f.dian][i].xian]=shu;
                q.push({e[f.dian][i].vv,shu,e[f.dian][i].xian});
            }
        }
    }
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> qq;
    for (int i=1;i<=m;i++)
        cin >> w[i];
    for (int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        for (int j=1;j<=k;j++)
        {
            int x;
            cin >> a[j] >> x;
            //cout << "(((" << a[j] << " " << i << endl;
            xianlu[a[j]].push_back(i);
            mp[make_pair(a[j],i)]=x;
            if (j>1)
            {
                e[a[j]].push_back({a[j-1],i});
                e[a[j-1]].push_back({a[j],i});
            }
        }
    }
    for (int i=1;i<=qq;i++)
    {
        cin >> shuru[i].x >> shuru[i].y;
        shuru[i].hao=i;
    }
    sort(shuru+1,shuru+qq+1,cmp);
    for (int i=1;i<=qq;i++)
    {
        if (shuru[i].x!=shuru[i-1].x) Dijkstra(shuru[i].x);
        int ans=9e18;
        for (int j=0;j<xianlu[shuru[i].y].size();j++)
        {
            //cout << "***" << shuru[i].y << " " << xianlu[shuru[i].y][j] << endl;
            ans=min(ans,dis[shuru[i].y][xianlu[shuru[i].y][j]]+mp[make_pair(shuru[i].y,xianlu[shuru[i].y][j])]+w[shuru[i].y]);
        }
        print[shuru[i].hao]=ans;
    }
    for (int i=1;i<=qq;i++)
        cout << print[i] << endl;

    return 0;
}
