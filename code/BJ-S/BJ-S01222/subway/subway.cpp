#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int M = 5e5 + 5;
int c , n , m , d , Q , W[M] , cur[M] , dis[100005] , vis[100005];
vector<int> a[505] , t[505] , v[100005] , w[100005];
struct st
{
    int pos , dis;
};
bool operator < (st x , st y)
{
    return x.dis > y.dis;
}
priority_queue<st> q;
struct quer
{
    int x , y , ans , i;
}b[100005];
bool cmp(quer x , quer y)
{
    return x.x < y.x;
}
bool cmp2(quer x , quer y)
{
    return x.i < y.i;
}
void dijkstra(int s)
{
    memset(dis , 0x3f , sizeof dis);
    memset(vis , 0 , sizeof vis);
    dis[s] = 0;
    q.push({s , 0});
    while(!q.empty())
    {
        int u = q.top().pos;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < v[u].size(); i++)
        {
            int p = v[u][i];
            if(dis[p] > dis[u] + w[u][i])
            {
                dis[p] = dis[u] + w[u][i];
                if(!vis[p]) q.push({p , dis[p]});
            }
        }
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1; i <= m; i++) cin >> W[i];
    for(int i = 1; i <= n; i++)
    {
        int k;cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int x , y;cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    if(1)
    {

        int super = 50000;
        for(int i = 1; i <= n; i++)
        {
            super++;
            for(int j = 0; j < a[i].size(); j++)
            {
                v[(a[i][j] - 1) * d + (++cur[a[i][j]])].push_back(super);
                v[super].push_back((a[i][j] - 1) * d + cur[a[i][j]]);
                w[(a[i][j] - 1) * d + cur[a[i][j]]].push_back(0);
                w[super].push_back(0);

                v[(a[i][j] - 1) * d + cur[a[i][j]]].push_back(1000 * d + a[i][j]);
                v[1000 * d + a[i][j]].push_back((a[i][j] - 1) * d + cur[a[i][j]]);
                w[(a[i][j] - 1) * d + cur[a[i][j]]].push_back(t[i][j]);
                w[1000 * d + a[i][j]].push_back(t[i][j]);
            }
        }
        int cur1 = 0;
        while(Q--)
        {
            cin >> b[++cur1].x >> b[cur1].y;
            b[cur1].i = cur1;
        }
        sort(b + 1 , b + cur1 + 1 , cmp);
        int head = 1;
        for(int i = 1; i <= cur1; )
        {
            dijkstra(b[i].x + 1000 * d);
            while(i <= cur1 && b[i].x == b[head].x) {b[i].ans = dis[b[i].y + 1000 * d];i++;}
            head = i;
        }
        sort(b + 1 , b + cur1 + 1 , cmp2);
        for(int i = 1; i <= cur1; i++)
            cout << b[i].ans + W[b[i].x] + W[b[i].y] << endl;
    }
    return 0;
}
