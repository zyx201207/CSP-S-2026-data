#include<bits/stdc++.h>
#define fir first
#define sec second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
    int x=0,t=1;
    char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-')
            t=-1;
        c=getchar();
    }
    while(c>='0' && c<='9')
    {
        x=(x<<1)+(x<<3)+(c^'0');
        c=getchar();
    }
    return x*t;
}
inline void write(ll x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>=10) write(x/10);
    putchar((x%10)^'0');
    return ;
}
inline void write_L(ll x)
{
    write(x);
    putchar('\n');
}
inline void write_(ll x)
{
    write(x);
    putchar(' ');
}
inline void write_P(pll x)
{
    write_(x.fir);
    write_L(x.sec);
}
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=5010;
ll x[2000010];
vector<int> e[N];
ll num[N],dist[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dist[s]=0;
    num[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:e[u])
        {
            if(dist[v]<dist[u]+1) continue;
            if(dist[v]==dist[u]+1)
            {
                num[v]+=num[u];
            }else if(dist[v]>dist[u]+1)
            {
                num[v]=num[u];
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    ull n=read(),d=read();
    for(int i=1;i<=n;i++)
        x[i]=read();
    if(n>5000)
    {
        ull D=abs(x[2]-x[1]);
        if(d<2*D) write_L(0);
        else
        {
            ll k=d/D;
            write_L(max(0ll,(ll)n+1-2*k));
        }
        return ;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            ull dis=abs(x[j]-x[i]);
            if(dis<=d) e[i].push_back(j);
        }
    ll ans=0;
    for(int u=1;u<=n;u++)
    {
        for(int i=1;i<=n;i++)
        {
            num[i]=0;
            dist[i]=inf;
        }
        bfs(u);
        for(int v=u+1;v<=n;v++)
            if(num[v]==2)
                ans++;
    }
    write_L(ans);
    for(int i=1;i<=n;i++)
        e[i].clear();
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int CASE=read(),t=read();
    while(t--)
        solve();
    return 0;
}

/*

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

17:10:00
[232,240] pts
100+[92,100]+40
S 1= !!!

17:50:00
100+[92,100]+48
[240,248] pts

万一分数线大于240呢（笑
万一前两个题样例全过结果挂飞了呢（笑
不会luogu的文章会有我吧lol
*/
