#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll CF,T,n,k,ans,cnt;
vector<ll> G[1000005];
bool vis[15],ok[15];
void work(ll x)
{
    ok[x]=1;
    for(auto y:G[x])
    {
        if(vis[y]&&!ok[y])
        {
            work(y);
        }
    }
}
void bfs(ll x)
{
    queue<pair<ll,ll> > q;
    q.push({x,0});
    while(q.size())
    {
        ll uf=q.front().first,us=q.front().second;
        q.pop();
        if(vis[uf])
        {
            cnt=max(cnt,us);
            return;
        }
        if(ok[uf])continue;
        ok[uf]=1;
        for(auto y:G[uf])
        {
            if(!ok[y])
            {
                q.push({y,us+1});
            }
        }
    }
}
void dfs(ll x)
{
    if(x>k)
    {
        cnt=0;
        for(int i=1;i<=n;i++)ok[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                if(!ok[i])
                {
                    work(i);
                    cnt++;
                }
            }
        }
        if(cnt>2)return;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                for(int j=1;j<=n;j++)ok[j]=0;
                bfs(i);
            }
        }
        ans=min(ans,cnt);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>CF>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<n;i++)
        {
            ll u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(n==k)
        {
            cout<<0<<endl;
            continue;
        }
        if(CF<=3)
        {
            ans=0x3f3f3f3f3f3f3f3f;
            dfs(1);
            cout<<ans<<endl;
            continue;
        }
        if(CF>=13&&CF<=14)
        {
            if(k>=n/2)cout<<1<<endl;
            else
            {
                ll tmp=(n/2-k+3)/4;
                cout<<tmp+1<<endl;
            }
            continue;
        }
    }
    return 0;
}
