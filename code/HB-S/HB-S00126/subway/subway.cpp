#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char getc()
{
    static constexpr int SIZ = 1 << 16;
    static char buf[SIZ],*p1 = buf,*p2 = buf;
    if(p1 == p2) p2 = (p1 = buf) + fread(buf,1,SIZ,stdin);
    return p1 == p2?EOF:*p1++;
}

template <typename T>
void read(T &x)
{
    bool f = false;
    char c;
    for(c = getc();!isdigit(c) && c != '-';c = getc());
    if(c == '-') c = getc(),f = true;
    for(x = 0;isdigit(c);c = getc())
        x = x * 10 + (c ^ '0');
    if(f) x = -x;
}

constexpr int N = 505,M = 500015;
constexpr ll inf = 1e18;
struct edge {int to,w;};
vector <edge> nl[M];
int c,n,m,d,q,wl[M];
ll dis[N][N];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(c),read(n),read(m),read(d),read(q);
    // scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++)
        read(wl[i]);
    for(int i = 1;i <= n;i++)
    {
        int len;
        read(len);
        for(int j = 0;j < len;j++)
        {
            int to,w;
            read(to),read(w);
            nl[to].push_back(edge{i,w});
        }
    }
    // cerr << clock() / 1e6 << "s" << endl;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            dis[i][j] = inf;
    for(int i = 1;i <= n;i++) dis[i][i] = 0;
    for(int i = 1;i <= m;i++)
        for(int j = 0;j < nl[i].size();j++)
            for(int k = j + 1;k < nl[i].size();k++)
            {
                auto &a = nl[i][j],&b = nl[i][k];
                dis[a.to][b.to] = min(dis[a.to][b.to],(ll)a.w + b.w);
                dis[b.to][a.to] = min(dis[b.to][a.to],(ll)a.w + b.w);
            }
    // cerr << clock() / 1e6 << "s" << endl;
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    // cerr << clock() / 1e6 << "s" << endl;
    for(int i = 1;i <= q;i++)
    {
        int x,y;
        read(x),read(y);
        ll ans = inf;
        for(int j = 0;j < nl[x].size();j++)
            for(int k = 0;k < nl[y].size();k++)
            {
                auto &a = nl[x][j],&b = nl[y][k];
                ans = min(ans,(ll)a.w + b.w + dis[a.to][b.to]);
            }
        ans += wl[x] + wl[y];
        printf("%lld\n",ans);
    }
    // int cnt = 0;
    // for(int i = 1;i <= m;i++) cnt += nl[i].size() * nl[i].size();
    // cerr << "cnt " << cnt << endl;
    // cerr << clock() / 1e6 << "s" << endl;
    return 0;
}