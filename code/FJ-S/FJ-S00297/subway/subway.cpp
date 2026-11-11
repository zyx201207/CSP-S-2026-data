#include<iostream>
#include<queue>
#include<vector>

#define ll long long
#define int long long

using namespace std;

const int N = 2e6 + 5;
const ll inf = 1e18 + 5;

int read()
{
    int sum = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9')
        sum = (sum << 3) + (sum << 1) + (ch ^ 48),
        ch = getchar();

    cout << sum << "\n";
    cout.flush();

    return sum;
}


// int tot,he[N],ve[N],ne[N],eg[N];
// void add(int u,int v,int w)
// {
//     ve[++tot] = v; eg[tot] = w;
//     ne[tot] = he[u]; he[u] = tot;
//     // cout << u << " " << v << " " << w << "\n";
// }
int c,n,m,d,q1,cnt,w[N];
struct node
{
    int x,y,res;
}ans[N];

vector<int> a[505];


struct node1
{
    int u,w;
//     int operator < (const node1 f) const
//     {
//         return f.w < w;
//     }
};
// priority_queue<node1> q;
int cnt2;
int cnt1,dis[N],vis[N];
void init()
{
    cnt1++; cnt2 = 0;
    for(int i = 1; i <= cnt; i++) dis[i] = inf;
    // while(q.size()) q.pop();
}

void chmin(int &a,int b)
{
    if(a > b) a = b;
}

vector<node1> a1[505];
vector<node1> ve[N];
int D[505][505],f[505][505];

void solve(int k)
{
    init(); dis[m + k] = 0;
    // q.push({m + k,0});
    // while(q.size())
    // {
    //     node1 t = q.top();
    //     q.pop();
    //     if(vis[t.u] == cnt1) continue;
    //     vis[t.u] = cnt1;
    //     // cout << t.u << "\n";
    //     if(t.u > m) cnt2++;
    //     if(cnt2 == n) break;

    //     for(int i = he[t.u]; i; i = ne[i])
    //     {
    //         int v = ve[i],w = eg[i];
    //         if(dis[v] > t.w + w)
    //         {
    //             dis[v] = t.w + w;
    //             q.push({v,dis[v]});
    //         }
    //     }
    // }

    // for(int i = 1; i <= cnt; i++)
        // cout << dis[i] << " ";
    // cout << "\n";

    for(int i = 1; i <= n; i++) chmin(dis[i + m],D[k][i]);

    // for(int i = 1; i <= cnt; i++)
        // cout << dis[i] << " ";
    // cout << "\n";

    for(int i = 1; i <= n; i++)
        for(auto j : a1[i])
            dis[j.u] = min(dis[j.u],dis[m + i] + j.w);

    // for(int i = 1; i <= cnt; i++)
        // cout << dis[i] << " ";
    // cout << "\n";

    for(auto i : a[k])
        ans[i].res = min(ans[i].res,dis[ans[i].x] + dis[ans[i].y]);
}



signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> c >> n >> m >> d >> q1;
    // c = read(); n = read(); m = read(); q1 = read();
    for(int i = 1; i <= m; i++) cin >> w[i];
    // w[i] = read();
    cnt = m;
    for(int i = 1; i <= n; i++)
    {
        ++cnt;
        int k; cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int u,w;
            cin >> u >> w;
            ve[u].push_back({i,w});
            // add(cnt,u,w); add(u,cnt,w);
            a1[i].push_back({u,w});
        }
    }
    // exit(0);

    for(int i = 1; i <= q1; i++)
    {
        cin >> ans[i].x >> ans[i].y;
        // ans[i].x = read(); ans[i].y = read();
        ans[i].res = inf;
        for(auto j : ve[ans[i].x])
        {
            // int v = ve[j] - m;
            a[j.u].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            // D[i][i]
            if(i != j) D[i][j] = inf;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < ve[i].size() - 1; j++)
            for(int l = j + 1; l < ve[i].size(); l++)
            {
                int we = ve[i][j].w + ve[i][l].w;
                chmin(D[ve[i][j].u][ve[i][l].u],we);
                chmin(D[ve[i][l].u][ve[i][j].u],we);
            }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                chmin(D[i][j],D[i][k] + D[k][j]);

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                chmin(D[i][j],D[i][k] + D[k][j]);

    // exit(0);

    for(int i = 1; i <= n; i++)
    {
        if(!a[i].size()) continue;
        solve(i);
    }

    // for(in)

    for(int i = 1; i <= q1; i++)
        // cout << w[ans[i].x] + w[ans[i].y] << "\n";
        // cout << ans[i].res << "\n";
        cout << ans[i].res + w[ans[i].x] + w[ans[i].y] << "\n";
}