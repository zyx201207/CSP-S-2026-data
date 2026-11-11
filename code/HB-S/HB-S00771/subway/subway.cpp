#include <bits/stdc++.h>
// #include <dragonpro.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
namespace DRA_FASTIO
{
    #ifdef __linux__
        #define getch() getchar_unlocked()
        // #define putch() putchar_unlocked()
    #else
        #define getch() _getchar_nolock()
        // #define putch() _putchar_nolock()
    #endif
    inline void putch(char ch)
    {putchar_unlocked(ch); return;}
    inline ll get_int()
    {
        ll res = 0 , flag = 1;
        char c = getch();
        while(c < '0' || c > '9')
            flag = -1 , c = getch();
        while(c >= '0' && c <= '9')
            res = res * 10 + c - '0' , c = getch();
        return flag * res;
    }
    inline void put_int(ll number)
    {
        char ch[30] , top = 0;
        if(number < 0)
            putch('-') , number = -number;
        do ch[++ top] = number % 10 + '0' , number /= 10;
        while(number);
        while(top)
            putch(ch[top --]);
        return;
    }
}
using namespace DRA_FASTIO;
static constexpr int MAXN = 510;
static constexpr int MAXM = 5e5 + 10;
static constexpr int INF = INT_MAX;
#define pr pair<ll,ll>
ll n , m , d , q , walktime[MAXM];
ll link[MAXN][MAXN] , dis[MAXN][MAXN];
struct stations
{vector<pr> bel;}st[MAXM]; // (lane , time)
inline void getmax(ll& aa , ll bb)
{aa = max(aa , bb); return;}
inline void getmin(ll& aa , ll bb)
{aa = min(aa , bb); return;}
namespace solution
{
    struct state
    {
        ll pos , dist;
        inline bool operator < \
        (const state another) const
        {return dist < another.dist;}
    };
    inline void Dijkstra(int start)
    {
        priority_queue<state> pq; // pos , nowdis
        pq.push({start , 0});
        while(!pq.empty())
        {
            state now = pq.top(); pq.pop();
            int pos = now.pos , dist = now.dist;
            for(int w = 1 ; w <= n ; w ++)
                if(w != pos && dist + link[pos][w] <= dis[start][w])
                {
                    dis[start][w] = dist + link[pos][w];
                    pq.push({w , dis[start][w]});
                }
            continue;
        } return;
    }
    inline void solve()
    {
        for(int i = 1 ; i <= n ; i ++) Dijkstra(i);

        // for(int i = 1 ; i <= n ; i ++)
        // {
        //     for(int j = 1 ; j <= n ; j ++)
        //         put_int(dis[i][j]) , putch(' ');
        //     putch('\n');
        // }

        while(q --)
        {
            int u = get_int() , v = get_int(); ll res = INF;
            for(size_t w_u = 0 ; w_u < st[u].bel.size() ; w_u ++)
            for(size_t w_v = 0 ; w_v < st[v].bel.size() ; w_v ++)
            {
                ll basic = st[u].bel[w_u].second + st[v].bel[w_v].second;
                getmin(res , dis[st[u].bel[w_u].first][st[v].bel[w_v].first] + basic);
                // cout << dis[st[u].bel[w_u].first][st[v].bel[w_v].first] << endl;
                // cout << st[u].bel[w_u].first << " " << st[v].bel[w_v].first << endl;
                // cout << st[u].bel[w_u].second << " " << st[v].bel[w_v].second << endl;
                // cout << basic << " " << res << endl;
            }
            put_int(res + walktime[u] + walktime[v]) , putch('\n');
        }
        return;
    }
}
int main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    int testcase = get_int(); // cout << testcase << endl;
    n = get_int() , m = get_int() , d = get_int() , q = get_int();
    for(int i = 1 ; i <= m ; i ++) walktime[i] = get_int();

    // for(int i = 1 ; i <= m ; i ++)
    //     cout << walktime[i] << " ";
    // putch('\n');

    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            if(i != j) link[i][j] = dis[i][j] = INF;
    for(int i = 1 ; i <= n ; i ++)
    {
        int k = get_int();
        for(int j = 1 ; j <= k ; j ++)
        {
            int idx = get_int() , t = get_int();
            for(size_t w = 0 ; w < st[idx].bel.size() ; w ++)
            {
                int cur_time = st[idx].bel[w].second + t;
                getmin(link[st[idx].bel[w].first][i] , cur_time);
                getmin(link[i][st[idx].bel[w].first] , cur_time);
            }
            st[idx].bel.push_back({i , t}); // lane i passes it
        }
    }

    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     for(int j = 1 ; j <= n ; j ++)
    //         cout << link[i][j] << " ";
    //     putch('\n');
    // }

    solution::solve();
    return 0;
}
// dragonpro-presents