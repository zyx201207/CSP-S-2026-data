#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll c,t,cnt;
ll ans,anss=INT_MAX;
ll n,k,p[N];
vector<ll> f[N];
struct node{
    ll pos,v;
};
void ddfs(ll x,ll fa)
{
    if(p[x]==1&&p[fa]==0)
    {
        cnt++;
    }
    for(ll i=0;i<f[x].size();i++)
    {
        ll wq=f[x][i];
        if(wq!=fa)
        {
            ddfs(wq,x);
        }
    }
    return ;
}
ll bfs(ll x)
{
    queue<node> q;
    map<ll,ll> mp;
    mp[x]=1;
    q.push({x,0});
    while(!q.empty())
    {
        node s=q.front();
        q.pop();
        if(p[s.pos]==1)
        {
            return s.v;
        }
        for(ll i=0;i<f[s.pos].size();i++)
        {
            ll h=f[s.pos][i];
            if(mp[h]!=1)
            {
                mp[h]=1;
                q.push({h,s.v+1});
            }
        }
    }
}
void dfs(ll x,ll yx)
{
    if(x==n+1)
    {
        if(yx!=k)
        {
            return ;
        }
        cnt=0;
        ddfs(1,0);
        if(cnt>2||cnt==0)
        {
            return ;
        }
        ans=INT_MIN;
        for(ll i=1;i<=n;i++)
        {
            if(p[i]==0)
            {
                ll ci=bfs(i);
                ans=max(ans,ci);
            }
        }
        anss=min(anss,ans);
        return ;
    }
    p[x]=1;
    dfs(x+1,yx+1);
    p[x]=0;
    dfs(x+1,yx);
    return ;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        anss=INT_MAX;
        cin>>n>>k;
        for(ll i=1;i<=n;i++)
        {
            p[i]=0;
            f[i].clear();
        }
        for(ll i=1;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            f[x].push_back(y);
            f[y].push_back(x);
        }
        dfs(1,0);
        cout<<anss<<"\n";
    }
    return 0;
}

