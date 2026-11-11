#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=5005;
ll c,t,n,d,a[N],dis[N],vis[N],cnt[N],ans;
vector<ll> e[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;

void dij(ll s)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[s]=0;q.push({0,s});
    while(!q.empty())
    {
        ll u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:e[u])
        {
            if(dis[u]+1<dis[v])
            {
                dis[v]=dis[u]+1;
                q.push({dis[v],v});
                cnt[v]=1;
            }
            else if(dis[u]+1==dis[v])cnt[v]++;
        }
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> c >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> d;
        for(ll i=1;i<=n;i++)cin >> a[i];
        for(ll i=1;i<=n;i++)e[i].clear();
        for(ll i=1;i<=n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                if(a[j]-a[i]<=d)e[i].push_back(j);
                else break;
            }
        }
        for(ll i=1;i<=n;i++)
        {
            memset(cnt,0,sizeof cnt);
            dij(i);
            for(ll j=i+1;j<=n;j++)if(cnt[j]==2)ans++;
            //for(ll j=i+1;j<=n;j++)printf("t=%lld  %lld->%lld cnt:%lld,dis:%lld\n",t,i,j,cnt[j],dis[j]);
        }
        cout << ans << endl;
    }

    return 0;
}
