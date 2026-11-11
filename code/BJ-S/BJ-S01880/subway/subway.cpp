#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,Q,jz[500005],dis[5005][5005],vis[500005],bel[500005];
struct node
{
    ll v,dis;
};
bool operator <(node a,node b)
{
    return a.dis>b.dis;
}
vector<node> ve[500005];
void dijk(ll st)
{
    dis[st][st]=0;
    priority_queue<node> q;
    q.push({st,0});
    while(!q.empty())
    {
        node u=q.top();
        q.pop();
        if(vis[u.v])continue;
        vis[u.v]=1;
        for(auto ne:ve[u.v])
        {
            ll v=ne.v,w=ne.dis;
            if(dis[st][v]>dis[st][u.v]+w)
            {
                dis[st][v]=dis[st][u.v]+w;
                q.push({v,dis[st][v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)
    {
        cin>>jz[i];
    }
    if(c<=11)
    {
        ll idx=m+1;
        for(int i=1;i<=n;i++)
        {
            ll k,lstidx;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                ll v,w;
                cin>>v>>w;
                bel[idx]=v;
                ve[idx].push_back({v,w});
                ve[v].push_back({idx,w});
                if(j!=1)
                {
                    ve[idx].push_back({lstidx,0});
                    ve[lstidx].push_back({idx,0});
                }
                lstidx=idx;
                idx++;
            }
        }
        for(int i=1;i<=idx;i++)
        {
            /*
            for(auto ne:ve[i])
            {
                cout<<i<<"->"<<ne.v<<":"<<ne.dis<<endl;
            }
            */
            for(int j=1;j<=idx;j++)
            {
                dis[i][j]=1e18;
            }
        }
        for(int i=1;i<=idx;i++)
        {
            for(int j=1;j<=idx;j++)
            {
                vis[j]=0;
            }
            dijk(i);
        }
        while(Q--)
        {
            ll l,r;
            cin>>l>>r;
            cout<<dis[l][r]+jz[l]+jz[r]<<endl;
        }
    }
    /*
    else if(12<=c&&c<=19)
    {
        ll T=0;
        for(int i=1;i<=n;i++)
        {
            ll k,lstidx;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                ll v,w;
                cin>>v>>w;
                bel[idx]=v;
                ve[idx].push_back({v,w});
                ve[v].push_back({idx,w});
                if(j!=1)
                {
                    ve[idx].push_back({lstidx,0});
                    ve[lstidx].push_back({idx,0});
                }
                lstidx=idx;
                idx++;
            }
        }
        for(int i=1;i<=idx;i++)
        {
            for(auto ne:ve[i])
            {
                cout<<i<<"->"<<ne.v<<":"<<ne.dis<<endl;
            }
            for(int j=1;j<=idx;j++)
            {
                dis[i][j]=1e18;
            }
        }
        for(int i=1;i<=idx;i++)
        {
            for(int j=1;j<=idx;j++)
            {
                vis[j]=0;
            }
            dijk(i);
        }
        while(Q--)
        {
            ll l,r;
            cin>>l>>r;
            cout<<dis[l][r]+jz[l]+jz[r]<<endl;
        }
    }
    */
    return 0;
}
