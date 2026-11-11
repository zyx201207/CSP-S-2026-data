#include <bits/stdc++.h>
#define vi vector<int>
#define pb emplace_back
using namespace std;
typedef long long ll;
constexpr int N=2e6+5,inf=1e9;
int cid,T;
int n;
ll d;
ll a[N];
vi e[N];
namespace sub1
{
    int dis[N];
    int diff[N];
    queue<int>q;
    void solve()
    {
        while(T--)
        {
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++)
                scanf("%lld",&a[i]);
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(abs(a[i]-a[j])<=d)
                        e[i].pb(j),e[j].pb(i);
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    dis[j]=inf,diff[j]=0;
                dis[i]=0,diff[i]=1;
                q.push(i);
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    if(diff[u]==2 && u>i)ans++;
                    for(auto v:e[u])
                    {
                        if(dis[v]==inf)
                        {
                            dis[v]=dis[u]+1;
                            diff[v]+=diff[u];
                            q.push(v);
                        }
                        else if(dis[v]==dis[u]+1)
                            diff[v]+=diff[u];
                    }
                }
            }
            printf("%d\n",ans);
            for(int i=1;i<=n;i++)
                e[i].clear();
        }
    }
}
namespace sub2
{
    void solve()
    {
        while(T--)
        {
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++)
                scanf("%lld",&a[i]);
            ll gc=a[2]-a[1];
            if(gc*2>d)
                printf("0\n");
            else
                printf("%lld\n",max(1ll*n-2ll*(d/gc)+1ll,0ll));
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&cid,&T);
    if(cid<=10)
        sub1::solve();
    else if(cid<=12)
        sub2::solve();
    return 0;
}