#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long inf = 1e18;
const long long mod = 998244353;
const long long N = 5e5 + 5;
int n , m;
int __;
int d;
int base[N];
struct node{
    int time , id;
    node(){}
    node(int _id , int _time){id = _id , time = _time;}
};
struct cmp{
    bool operator() (const node& x , const node& y) const{
        return x.time > y.time;
    }
};
vector<node>station[N];
int kk[N];
int aa[505][505];
vector<node>a[505];

int dis[505][505];
void bfs(int S)
{
    for(int i = 1 ; i <= n ; i++)dis[S][i] = inf;
    dis[S][S] = 0;
    priority_queue<node , vector<node> , cmp>q;
    int u , t , v , w;
    q.push(node(S , 0));
    while(!q.empty())
    {
        u = q.top().id , t = q.top().time;
        q.pop();
        if(t > dis[S][u])continue;
        for(node gto : a[u])
        {
            v = gto.id , w = gto.time;
            if(dis[S][v] <= t + w)continue;
            dis[S][v] = t + w;
            q.push(node(v , t + w));
        }
    }
    return ;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    int ___;
    cin >> __ >> n >> m >> d >> ___;
    for(int i = 1 ; i <= m ; i++)cin >> base[i];
    int x , y;
    for(int i = 1 ; i <= n ; i++)for(int j = 1 ; j <= n ; j++)aa[i][j] = inf , (i == j ? aa[i][j] = 0 : aa[i][j] = aa[i][j]);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> kk[i];
        for(int j = 1 ; j <= kk[i] ; j++)cin >> x >> y , station[x].push_back(node(i , y));
    }

    for(int id = 1 ; id <= m ; id++)
    {
        for(node u : station[id])
        {
            for(node v : station[id])
            {
                if(u.id == v.id)continue;
                aa[u.id][v.id] = aa[v.id][u.id] = min(aa[u.id][v.id] , u.time + v.time);
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i == j)continue;
            if(aa[i][j] == inf)continue;
            a[i].push_back(node(j , aa[i][j]));
            //cerr << "a:" << i << ' ' << j << endl;
        }
    }
    for(int i = 1 ; i <= n ; i++)bfs(i);
    /*
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cerr << aa[i][j] << ' ';
        }
        cerr << endl;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cerr << dis[i][j] << ' ';
        }
        cerr << endl;
    }
    */
    int ans;
    while(___--)
    {
        cin >> x >> y;
        ans = inf;
        for(node u : station[x])
        {
            for(node v : station[y])
            {
                ans = min(ans , u.time + v.time + dis[u.id][v.id]);
                //cerr << x << ' ' << y << ':' << u.id << ' ' << v.id << ' ' << ans << ' ' << dis[u.id][v.id] << endl;
            }
        }
        cout << ans + base[x] + base[y] << endl;
    }
    return 0;
}
