#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,x[2000006],ans,n,d,cntl,cntr,pos,cnt[305],dis[305],vis[305];
const ll inf = 0x3f3f3f3f3f3f3f3f;
vector<ll>mp[305];
queue<ll>q;
ll count(ll l,ll r)
{
    if(l>r)return 0;
    ll lid = (lower_bound(x+1,x+n+1,l)-x),rid = (upper_bound(x+1,x+n+1,r)-x);
    return rid-lid;
}
void run1()
{

}
void dfs(ll u)
{
    q.push(u);
    while(q.size())
    {
        u = q.front();
        q.pop();
        for(ll v:mp[u])
        {
            if(dis[v]<dis[u]+1)continue;
            if(dis[v] == dis[u]+1)
            {
                cnt[v]+=cnt[u];
                continue;
            }
            cnt[v] = cnt[u];
            dis[v] = dis[u]+1;
            q.push(v);
        }
    }
}
void run2()
{
    cin>>n>>d;
    for(ll i = 1;i<=n;i++)cin>>x[i];
    for(ll i = 1;i<=n;i++)
    {
        mp[i].clear();
    }
    for(ll i = 1;i<=n;i++)
    {
        for(ll j = 1;j<=n;j++)
        {
            if(abs(x[i]-x[j])<=d)mp[i].push_back(j);
        }
    }
    ans = 0;
    for(ll i = 1;i<=n;i++)
    {
        for(ll j = 1;j<=n;j++)cnt[j] = vis[j] = 0,dis[j] = 0x3f3f3f3f3f3f3f3f;
        cnt[i] = 1;
        dis[i] = 0;
        dfs(i);
        for(ll j = 1;j<=n;j++)if(cnt[j] == 2)ans++;
    }
    ans/=2;
    cout<<ans<<'\n';
}
void run()
{
    ans = 0;
    cin>>n>>d;
    for(ll i = 1;i<=n;i++)cin>>x[i];
    x[0] = -inf;
    if(c == 11||c == 12)
    {
        run1();
        return;
    }
    if(n<=300)
    {
        run2();
        return;
    }
    ans = 0;
    for(ll i = 1;i<=n;i++)
    {
        if(count(x[i]-d,x[i]+d) == n)
        {
            pos = i;
            break;
        }
    }
    for(ll i = 1;i<=n;i++)
    {
        if(i == pos)continue;
        ans+=count(x[i]-d,x[i]-1)*count(x[i]+1,x[i]+d);
    }
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)run2();
}